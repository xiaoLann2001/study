#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QTimer>
#include <QKeyEvent>

class CubeWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit CubeWidget(QWidget *parent = nullptr);
    ~CubeWidget() override;

protected:
    void initializeGL() override;           // 初始化 OpenGL
    void resizeGL(int w, int h) override;   // 窗口大小变化
    void paintGL() override;                // 绘制函数
    void keyPressEvent(QKeyEvent *event) override; // 键盘事件

private slots:
    void onTimeout(); // 定时器槽函数，控制自动旋转

private:
    void setupShaders(); // 初始化着色器
    void setupCube();    // 初始化立方体顶点数据

    QOpenGLShaderProgram *program = nullptr;
    QOpenGLBuffer *vbo = nullptr;
    QOpenGLVertexArrayObject *vao = nullptr;
    QTimer timer;        // 控制自动旋转的定时器
    float angleX = 0.0f; // 绕X轴旋转角度
    float angleY = 0.0f; // 绕Y轴旋转角度
    bool autoRotate = true; // 自动旋转开关
};

#endif // CUBEWIDGET_H
