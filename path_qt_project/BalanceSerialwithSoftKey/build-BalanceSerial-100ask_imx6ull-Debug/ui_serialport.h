/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serialport
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *comboBox_SerialPort;
    QLabel *label_5;
    QComboBox *comboBox_BaudRate;
    QLabel *label_6;
    QComboBox *comboBox_StopBit;
    QLabel *label_7;
    QComboBox *comboBox_DataBit;
    QLabel *label_8;
    QComboBox *comboBox_Pority;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_SearchSerialport;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_ClearRcv;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_HexDisplay;
    QCheckBox *checkBox_HexSend;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Send;
    QPushButton *pushButton_ClearSend;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPlainTextEdit *sendTextEdit;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPlainTextEdit *receiveTextEdit;

    void setupUi(QWidget *Serialport)
    {
        if (Serialport->objectName().isEmpty())
            Serialport->setObjectName(QString::fromUtf8("Serialport"));
        Serialport->resize(1010, 580);
        Serialport->setMinimumSize(QSize(1010, 580));
        Serialport->setMaximumSize(QSize(1010, 580));
        layoutWidget = new QWidget(Serialport);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(680, 0, 301, 557));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        comboBox_SerialPort = new QComboBox(layoutWidget);
        comboBox_SerialPort->setObjectName(QString::fromUtf8("comboBox_SerialPort"));
        QFont font1;
        font1.setPointSize(12);
        comboBox_SerialPort->setFont(font1);

        gridLayout->addWidget(comboBox_SerialPort, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        comboBox_BaudRate = new QComboBox(layoutWidget);
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->addItem(QString());
        comboBox_BaudRate->setObjectName(QString::fromUtf8("comboBox_BaudRate"));
        comboBox_BaudRate->setFont(font1);

        gridLayout->addWidget(comboBox_BaudRate, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        comboBox_StopBit = new QComboBox(layoutWidget);
        comboBox_StopBit->addItem(QString());
        comboBox_StopBit->addItem(QString());
        comboBox_StopBit->addItem(QString());
        comboBox_StopBit->setObjectName(QString::fromUtf8("comboBox_StopBit"));
        comboBox_StopBit->setFont(font1);

        gridLayout->addWidget(comboBox_StopBit, 2, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        comboBox_DataBit = new QComboBox(layoutWidget);
        comboBox_DataBit->addItem(QString());
        comboBox_DataBit->addItem(QString());
        comboBox_DataBit->addItem(QString());
        comboBox_DataBit->addItem(QString());
        comboBox_DataBit->setObjectName(QString::fromUtf8("comboBox_DataBit"));
        comboBox_DataBit->setFont(font1);

        gridLayout->addWidget(comboBox_DataBit, 3, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        comboBox_Pority = new QComboBox(layoutWidget);
        comboBox_Pority->addItem(QString());
        comboBox_Pority->addItem(QString());
        comboBox_Pority->addItem(QString());
        comboBox_Pority->setObjectName(QString::fromUtf8("comboBox_Pority"));
        comboBox_Pority->setFont(font1);

        gridLayout->addWidget(comboBox_Pority, 4, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_SearchSerialport = new QPushButton(layoutWidget);
        pushButton_SearchSerialport->setObjectName(QString::fromUtf8("pushButton_SearchSerialport"));
        pushButton_SearchSerialport->setMinimumSize(QSize(0, 40));
        pushButton_SearchSerialport->setMaximumSize(QSize(16777215, 40));
        pushButton_SearchSerialport->setFont(font);

        horizontalLayout_3->addWidget(pushButton_SearchSerialport);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_Open = new QPushButton(layoutWidget);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setMinimumSize(QSize(0, 40));
        pushButton_Open->setMaximumSize(QSize(16777215, 40));
        pushButton_Open->setFont(font);

        horizontalLayout->addWidget(pushButton_Open);

        pushButton_ClearRcv = new QPushButton(layoutWidget);
        pushButton_ClearRcv->setObjectName(QString::fromUtf8("pushButton_ClearRcv"));
        pushButton_ClearRcv->setMinimumSize(QSize(0, 40));
        pushButton_ClearRcv->setMaximumSize(QSize(16777215, 40));
        pushButton_ClearRcv->setFont(font);

        horizontalLayout->addWidget(pushButton_ClearRcv);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_HexDisplay = new QCheckBox(layoutWidget);
        checkBox_HexDisplay->setObjectName(QString::fromUtf8("checkBox_HexDisplay"));
        checkBox_HexDisplay->setFont(font);
        checkBox_HexDisplay->setChecked(true);

        verticalLayout->addWidget(checkBox_HexDisplay);

        checkBox_HexSend = new QCheckBox(layoutWidget);
        checkBox_HexSend->setObjectName(QString::fromUtf8("checkBox_HexSend"));
        checkBox_HexSend->setFont(font);
        checkBox_HexSend->setChecked(true);

        verticalLayout->addWidget(checkBox_HexSend);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Send = new QPushButton(layoutWidget);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setEnabled(false);
        pushButton_Send->setMinimumSize(QSize(0, 40));
        pushButton_Send->setMaximumSize(QSize(16777215, 40));
        pushButton_Send->setFont(font);

        horizontalLayout_2->addWidget(pushButton_Send);

        pushButton_ClearSend = new QPushButton(layoutWidget);
        pushButton_ClearSend->setObjectName(QString::fromUtf8("pushButton_ClearSend"));
        pushButton_ClearSend->setMinimumSize(QSize(0, 40));
        pushButton_ClearSend->setMaximumSize(QSize(16777215, 40));
        pushButton_ClearSend->setFont(font);

        horizontalLayout_2->addWidget(pushButton_ClearSend);


        verticalLayout_4->addLayout(horizontalLayout_2);

        layoutWidget_2 = new QWidget(Serialport);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 320, 661, 231));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        sendTextEdit = new QPlainTextEdit(layoutWidget_2);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
        sendTextEdit->setFont(font1);

        verticalLayout_3->addWidget(sendTextEdit);

        layoutWidget_3 = new QWidget(Serialport);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 0, 661, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        receiveTextEdit = new QPlainTextEdit(layoutWidget_3);
        receiveTextEdit->setObjectName(QString::fromUtf8("receiveTextEdit"));
        receiveTextEdit->setFont(font1);
        receiveTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(receiveTextEdit);


        retranslateUi(Serialport);

        QMetaObject::connectSlotsByName(Serialport);
    } // setupUi

    void retranslateUi(QWidget *Serialport)
    {
        Serialport->setWindowTitle(QApplication::translate("Serialport", "Form", nullptr));
        label_4->setText(QApplication::translate("Serialport", "<html><head/><body><p>\344\270\262\345\217\243</p></body></html>", nullptr));
        label_5->setText(QApplication::translate("Serialport", "<html><head/><body><p>\346\263\242\347\211\271\347\216\207</p></body></html>", nullptr));
        comboBox_BaudRate->setItemText(0, QApplication::translate("Serialport", "9600", nullptr));
        comboBox_BaudRate->setItemText(1, QApplication::translate("Serialport", "19200", nullptr));
        comboBox_BaudRate->setItemText(2, QApplication::translate("Serialport", "38400", nullptr));
        comboBox_BaudRate->setItemText(3, QApplication::translate("Serialport", "57600", nullptr));
        comboBox_BaudRate->setItemText(4, QApplication::translate("Serialport", "115200", nullptr));

        label_6->setText(QApplication::translate("Serialport", "<html><head/><body><p>\345\201\234\346\255\242\344\275\215</p></body></html>", nullptr));
        comboBox_StopBit->setItemText(0, QApplication::translate("Serialport", "1", nullptr));
        comboBox_StopBit->setItemText(1, QApplication::translate("Serialport", "1.5", nullptr));
        comboBox_StopBit->setItemText(2, QApplication::translate("Serialport", "2", nullptr));

        label_7->setText(QApplication::translate("Serialport", "<html><head/><body><p>\346\225\260\346\215\256\344\275\215</p></body></html>", nullptr));
        comboBox_DataBit->setItemText(0, QApplication::translate("Serialport", "5", nullptr));
        comboBox_DataBit->setItemText(1, QApplication::translate("Serialport", "6", nullptr));
        comboBox_DataBit->setItemText(2, QApplication::translate("Serialport", "7", nullptr));
        comboBox_DataBit->setItemText(3, QApplication::translate("Serialport", "8", nullptr));

        comboBox_DataBit->setCurrentText(QApplication::translate("Serialport", "5", nullptr));
        label_8->setText(QApplication::translate("Serialport", "<html><head/><body><p>\345\245\207\345\201\266\346\240\241\351\252\214</p></body></html>", nullptr));
        comboBox_Pority->setItemText(0, QApplication::translate("Serialport", "\346\227\240", nullptr));
        comboBox_Pority->setItemText(1, QApplication::translate("Serialport", "\345\245\207\346\240\241\351\252\214", nullptr));
        comboBox_Pority->setItemText(2, QApplication::translate("Serialport", "\345\201\266\346\240\241\351\252\214", nullptr));

        pushButton_SearchSerialport->setText(QApplication::translate("Serialport", "\346\237\245\346\211\276\345\217\257\347\224\250\344\270\262\345\217\243", nullptr));
        pushButton_Open->setText(QApplication::translate("Serialport", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButton_ClearRcv->setText(QApplication::translate("Serialport", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        checkBox_HexDisplay->setText(QApplication::translate("Serialport", "16\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        checkBox_HexSend->setText(QApplication::translate("Serialport", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        pushButton_Send->setText(QApplication::translate("Serialport", "\345\217\221\351\200\201", nullptr));
        pushButton_ClearSend->setText(QApplication::translate("Serialport", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        label_3->setText(QApplication::translate("Serialport", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        label_2->setText(QApplication::translate("Serialport", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serialport: public Ui_Serialport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
