#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>

class ImageWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = nullptr);
    ~ImageWidget() override;

    void setImage(const QString &path); // 设置图片路径

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void setupShaders();
    void setupQuad();

    QOpenGLShaderProgram *program = nullptr;
    QOpenGLBuffer *vbo = nullptr;
    QOpenGLVertexArrayObject *vao = nullptr;
    QOpenGLTexture *texture = nullptr;
};

#endif // IMAGEWIDGET_H
