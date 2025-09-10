#include <QApplication>
#include "CubeWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CubeWidget w;
    w.resize(800, 600);
    w.show();

    return a.exec();
}
