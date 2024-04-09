#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);  //默认显示第一页
}

Widget::~Widget()
{
    delete ui;
}
