#include <QApplication>
#include <QTimer>
#include "ImageWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ImageWidget w;
    w.resize(800, 600);
    w.show();

    // 延迟加载图片，确保 OpenGL 上下文可用
    QTimer::singleShot(0, [&w](){
        w.setImage("/home/xiaolan/study/path_qt_project/OpenGLImageDemo/test.jpg");
    });

    return a.exec();
}

