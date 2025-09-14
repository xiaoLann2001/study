#include "ImageWidget.h"
#include <QOpenGLShaderProgram>
#include <QImage>
#include <QDebug>

// 构造函数
ImageWidget::ImageWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    // 这里没有做额外初始化，OpenGL相关初始化在 initializeGL 中进行
}

// 析构函数
ImageWidget::~ImageWidget()
{
    makeCurrent(); // 确保在当前 OpenGL 上下文中删除资源
    delete texture; // 删除纹理对象
    delete vbo;     // 删除顶点缓冲对象
    delete program; // 删除着色器程序
    delete vao;     // 删除顶点数组对象
    doneCurrent();  // 释放当前 OpenGL 上下文
}

// OpenGL 初始化函数，类似于初始化画布和状态
void ImageWidget::initializeGL()
{
    initializeOpenGLFunctions(); // 初始化 OpenGL 函数指针

    // 开启混合（用于支持透明度）
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // 设置着色器和四边形顶点数据
    setupShaders();
    setupQuad();
}

// 窗口尺寸改变时调用
void ImageWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h); // 设置视口大小
}

// 每次绘制窗口时调用
void ImageWidget::paintGL()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // 设置背景颜色
    glClear(GL_COLOR_BUFFER_BIT);          // 清空颜色缓冲

    if (!texture) return; // 如果没有加载纹理则直接返回

    program->bind();  // 绑定着色器程序
    vao->bind();      // 绑定顶点数组对象
    texture->bind();  // 绑定纹理对象

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); // 绘制四边形（纹理贴图）

    texture->release(); // 释放纹理
    vao->release();     // 释放顶点数组对象
    program->release(); // 释放着色器程序
}

// 设置图片路径并创建 OpenGL 纹理
void ImageWidget::setImage(const QString &path)
{
    QImage img(path);
    if (img.isNull()) {
        qWarning() << "Failed to load image:" << path;
        return;
    }

    // 转换为 RGBA 格式，保证纹理数据格式兼容
    img = img.convertToFormat(QImage::Format_RGBA8888);

    makeCurrent(); // 激活 OpenGL 上下文，才能操作纹理

    if (texture) delete texture;       // 如果已有纹理，先删除
    texture = new QOpenGLTexture(img); // 创建新纹理

    doneCurrent(); // 释放上下文

    update(); // 触发重绘，将新纹理显示出来
}

// 设置顶点着色器和片段着色器
void ImageWidget::setupShaders()
{
    program = new QOpenGLShaderProgram(this);

    // 顶点着色器：处理顶点位置和纹理坐标
    const char *vertex_src =
        "#version 120\n"
        "attribute vec2 pos;\n"       // 顶点位置
        "attribute vec2 texCoord;\n"  // 顶点纹理坐标
        "varying vec2 vTexCoord;\n"   // 传递给片段着色器的变量
        "void main(){\n"
        "  gl_Position = vec4(pos, 0.0, 1.0);\n" // 设置顶点屏幕坐标
        "  vTexCoord = texCoord;\n"              // 传递纹理坐标
        "}";

    // 片段着色器：根据纹理坐标取样纹理颜色
    const char *fragment_src =
        "#version 120\n"
        "varying vec2 vTexCoord;\n"   // 接收顶点着色器传递的纹理坐标
        "uniform sampler2D tex;\n"    // 纹理采样器
        "void main(){\n"
        "  gl_FragColor = texture2D(tex, vTexCoord);\n" // 输出纹理颜色
        "}";

    program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertex_src);   // 添加顶点着色器
    program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragment_src); // 添加片段着色器
    program->link();       // 链接着色器程序
    program->bind();       // 使用着色器
    program->setUniformValue("tex", 0); // 设置纹理单元
}

// 设置四边形顶点和纹理坐标
void ImageWidget::setupQuad()
{
    // 顶点数据：x, y, u, v
    static const float vertices[] = {
        -1.0f, -1.0f,  0.0f, 1.0f, // 左下
         1.0f, -1.0f,  1.0f, 1.0f, // 右下
        -1.0f,  1.0f,  0.0f, 0.0f, // 左上
         1.0f,  1.0f,  1.0f, 0.0f  // 右上
    };

    vao = new QOpenGLVertexArrayObject(this);
    vao->create();
    vao->bind(); // 绑定 VAO

    vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo->create();
    vbo->bind(); 
    vbo->allocate(vertices, sizeof(vertices)); // 上传顶点数据到 GPU

    // 获取着色器中变量位置
    int posLoc = program->attributeLocation("pos");
    int texLoc = program->attributeLocation("texCoord");

    // 启用顶点属性数组并设置数据格式
    program->enableAttributeArray(posLoc);
    program->setAttributeBuffer(posLoc, GL_FLOAT, 0, 2, 4 * sizeof(float));

    program->enableAttributeArray(texLoc);
    program->setAttributeBuffer(texLoc, GL_FLOAT, 2 * sizeof(float), 2, 4 * sizeof(float));

    vao->release(); // 释放 VAO
    vbo->release(); // 释放 VBO
}
