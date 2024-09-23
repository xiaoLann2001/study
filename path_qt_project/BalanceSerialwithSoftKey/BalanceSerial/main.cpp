#include "widget.h"
#include <QApplication>
#include <QByteArray>

int main(int argc, char *argv[])
{
    // 启用虚拟键盘
    qputenv("QT_IM_MODULE", QByteArray("Qt5Input"));

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
