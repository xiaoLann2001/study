/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <control.h>
#include <pid.h>
#include <serialport.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    Serialport *Serialportwidget;
    QWidget *tab_2;
    PID *PIDwidget;
    QWidget *tab_3;
    Control *Controlwidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setEnabled(true);
        Widget->resize(1024, 600);
        Widget->setMinimumSize(QSize(1024, 600));
        Widget->setMaximumSize(QSize(1024, 600));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 1020, 590));
        tabWidget->setMinimumSize(QSize(1020, 590));
        tabWidget->setMaximumSize(QSize(1020, 590));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        Serialportwidget = new Serialport(tab);
        Serialportwidget->setObjectName(QString::fromUtf8("Serialportwidget"));
        Serialportwidget->setGeometry(QRect(10, 10, 1010, 580));
        Serialportwidget->setMinimumSize(QSize(1010, 580));
        Serialportwidget->setMaximumSize(QSize(1010, 580));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        PIDwidget = new PID(tab_2);
        PIDwidget->setObjectName(QString::fromUtf8("PIDwidget"));
        PIDwidget->setGeometry(QRect(10, 10, 1010, 580));
        PIDwidget->setMinimumSize(QSize(1010, 580));
        PIDwidget->setMaximumSize(QSize(1010, 580));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        Controlwidget = new Control(tab_3);
        Controlwidget->setObjectName(QString::fromUtf8("Controlwidget"));
        Controlwidget->setGeometry(QRect(10, 10, 1010, 580));
        Controlwidget->setMinimumSize(QSize(1010, 580));
        Controlwidget->setMaximumSize(QSize(1010, 580));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "by Songgq", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "PID\350\260\203\350\257\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "\346\216\247\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
