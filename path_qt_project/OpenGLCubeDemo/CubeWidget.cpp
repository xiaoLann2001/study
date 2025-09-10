#include "CubeWidget.h"
#include <QMatrix4x4>
#include <QDebug>

CubeWidget::CubeWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);  // 确保能接收键盘事件
    connect(&timer, &QTimer::timeout, this, &CubeWidget::onTimeout);
    timer.start(16); // ~60fps 自动刷新
}

CubeWidget::~CubeWidget()
{
    makeCurrent();
    delete vbo;
    delete program;
    delete vao;
    doneCurrent();
}

// 初始化 OpenGL 状态和资源
void CubeWidget::initializeGL()
{
    initializeOpenGLFunctions();   // 初始化 OpenGL 函数
    glEnable(GL_DEPTH_TEST);       // 启用深度测试

    setupShaders();                // 初始化顶点/片段着色器
    setupCube();                   // 初始化立方体顶点数据
}

// 窗口大小变化时更新视口
void CubeWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

// 渲染函数，每帧被调用
void CubeWidget::paintGL()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // 背景色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除缓冲

    // 构建模型矩阵
    QMatrix4x4 model;
    model.rotate(angleX, 1, 0, 0);
    model.rotate(angleY, 0, 1, 0);

    // 构建视图矩阵
    QMatrix4x4 view;
    view.translate(0, 0, -5);

    // 构建投影矩阵
    QMatrix4x4 projection;
    projection.perspective(45.0f, float(width())/height(), 0.1f, 100.0f);

    // 计算最终MVP矩阵
    QMatrix4x4 mvp = projection * view * model;

    program->bind();
    program->setUniformValue("mvp", mvp);

    vao->bind();
    glDrawArrays(GL_TRIANGLES, 0, 36); // 绘制36个顶点（12个三角形）
    vao->release();
    program->release();
}

// 键盘事件：支持WASD旋转，R重置，空格开关自动旋转
void CubeWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_W:   angleX -= 5.0f; break;
        case Qt::Key_S:   angleX += 5.0f; break;
        case Qt::Key_A:   angleY -= 5.0f; break;
        case Qt::Key_D:   angleY += 5.0f; break;
        case Qt::Key_R:   angleX = angleY = 0; break;
        case Qt::Key_Space: autoRotate = !autoRotate; break;
    }
    update(); // 触发重绘
}

// 定时器槽函数，用于自动旋转
void CubeWidget::onTimeout()
{
    if (autoRotate) {
        angleX += 1.0f;
        angleY += 1.0f;
    }
    update();
}

// 初始化顶点/片段着色器
void CubeWidget::setupShaders()
{
    program = new QOpenGLShaderProgram(this);

    const char *vertex_src =
        "#version 120\n"
        "attribute vec3 pos;\n"
        "attribute vec3 color;\n"
        "varying vec3 vColor;\n"
        "uniform mat4 mvp;\n"
        "void main(){\n"
        "  gl_Position = mvp * vec4(pos, 1.0);\n"
        "  vColor = color;\n"
        "}";

    const char *fragment_src =
        "#version 120\n"
        "varying vec3 vColor;\n"
        "void main(){\n"
        "  gl_FragColor = vec4(vColor, 1.0);\n"
        "}";

    program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertex_src);
    program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragment_src);
    program->link();
    program->bind();
}

// 初始化立方体顶点数据和VBO/VAO
void CubeWidget::setupCube()
{
    static const float cubeData[] = {
        // positions         // colors
        // Front face
        -1,-1, 1,  1,0,0,  1,-1, 1,  0,1,0,  1, 1, 1,  0,0,1,
        1, 1, 1,  1,1,0,  -1,-1, 1,  1,0,0,  -1,1, 1,  0,1,1,
        // Back face
        -1,-1,-1,  1,0,0,  1, 1,-1,  1,1,0,  1,-1,-1,  0,1,0,
        1, 1,-1,  0,0,1,  -1,-1,-1,  1,0,0,  -1,1,-1,  0,1,1,
        // Left face
        -1,-1,-1,  1,0,0,  -1,1,-1,  0,1,0,  -1,-1, 1,  1,1,0,
        -1,1, 1,   0,0,1,  -1,-1, 1,  1,1,0,  -1,1,-1,  0,1,0,
        // Right face
        1,-1,-1,   1,0,0,   1,-1, 1,  0,1,0,  1,1, 1,  0,0,1,
        1,1, 1,    0,0,1,   1,1,-1,  1,1,0,  1,-1,-1,  1,0,0,
        // Top face
        -1, 1,-1,  1,0,0,   1,1,-1,  0,1,0,  1,1, 1,  0,0,1,
        1,1, 1,    0,0,1,  -1, 1, 1,  1,1,0,  -1,1,-1,  1,0,0,
        // Bottom face
        -1,-1,-1,  1,0,0,   -1,-1, 1, 0,1,0,   1,-1, 1, 0,0,1,
        1,-1, 1,   0,0,1,    1,-1,-1, 1,1,0,  -1,-1,-1, 1,0,0
    };

    vao = new QOpenGLVertexArrayObject(this);
    vao->create();
    vao->bind();

    vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo->create();
    vbo->bind();
    vbo->allocate(cubeData, sizeof(cubeData));

    int posLoc = program->attributeLocation("pos");
    int colorLoc = program->attributeLocation("color");

    program->enableAttributeArray(posLoc);
    program->setAttributeBuffer(posLoc, GL_FLOAT, 0, 3, 6 * sizeof(float));

    program->enableAttributeArray(colorLoc);
    program->setAttributeBuffer(colorLoc, GL_FLOAT, 3 * sizeof(float), 3, 6 * sizeof(float));

    vao->release();
    vbo->release();
}
