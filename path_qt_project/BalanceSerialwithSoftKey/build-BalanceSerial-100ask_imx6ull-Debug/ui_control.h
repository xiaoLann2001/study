/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QPushButton *pushButton_Stop;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Move_forward;
    QPushButton *pushButton_Move_backward;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Turn_left;
    QPushButton *pushButton_Turn_right;

    void setupUi(QWidget *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QString::fromUtf8("Control"));
        Control->resize(1010, 580);
        Control->setMinimumSize(QSize(1010, 580));
        pushButton_Stop = new QPushButton(Control);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(210, 240, 100, 100));
        pushButton_Stop->setMinimumSize(QSize(100, 100));
        pushButton_Stop->setMaximumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(16);
        pushButton_Stop->setFont(font);
        widget = new QWidget(Control);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 180, 102, 214));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Move_forward = new QPushButton(widget);
        pushButton_Move_forward->setObjectName(QString::fromUtf8("pushButton_Move_forward"));
        pushButton_Move_forward->setMinimumSize(QSize(100, 100));
        pushButton_Move_forward->setMaximumSize(QSize(100, 100));
        pushButton_Move_forward->setFont(font);

        verticalLayout->addWidget(pushButton_Move_forward);

        pushButton_Move_backward = new QPushButton(widget);
        pushButton_Move_backward->setObjectName(QString::fromUtf8("pushButton_Move_backward"));
        pushButton_Move_backward->setMinimumSize(QSize(100, 100));
        pushButton_Move_backward->setMaximumSize(QSize(100, 100));
        pushButton_Move_backward->setFont(font);

        verticalLayout->addWidget(pushButton_Move_backward);

        widget1 = new QWidget(Control);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(690, 240, 214, 102));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Turn_left = new QPushButton(widget1);
        pushButton_Turn_left->setObjectName(QString::fromUtf8("pushButton_Turn_left"));
        pushButton_Turn_left->setMinimumSize(QSize(100, 100));
        pushButton_Turn_left->setMaximumSize(QSize(100, 100));
        pushButton_Turn_left->setFont(font);

        horizontalLayout->addWidget(pushButton_Turn_left);

        pushButton_Turn_right = new QPushButton(widget1);
        pushButton_Turn_right->setObjectName(QString::fromUtf8("pushButton_Turn_right"));
        pushButton_Turn_right->setMinimumSize(QSize(100, 100));
        pushButton_Turn_right->setMaximumSize(QSize(100, 100));
        pushButton_Turn_right->setFont(font);

        horizontalLayout->addWidget(pushButton_Turn_right);


        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QWidget *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "Form", nullptr));
        pushButton_Stop->setText(QApplication::translate("Control", "\345\201\234\346\255\242", nullptr));
        pushButton_Move_forward->setText(QApplication::translate("Control", "\345\211\215\350\277\233", nullptr));
        pushButton_Move_backward->setText(QApplication::translate("Control", "\345\220\216\351\200\200", nullptr));
        pushButton_Turn_left->setText(QApplication::translate("Control", "\345\267\246\350\275\254", nullptr));
        pushButton_Turn_right->setText(QApplication::translate("Control", "\345\217\263\350\275\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
