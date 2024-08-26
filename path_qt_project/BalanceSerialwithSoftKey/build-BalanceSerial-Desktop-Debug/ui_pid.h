/********************************************************************************
** Form generated from reading UI file 'pid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PID_H
#define UI_PID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_PID
{
public:
    QTabWidget *tabWidget;
    QWidget *paramters;
    QGroupBox *groupBox_Stand;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_Vertical_Kd;
    QDoubleSpinBox *doubleSpinBox_Vertical_Kp;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_Velocity;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_Velocity_Kp;
    QDoubleSpinBox *doubleSpinBox_Velocity_Ki;
    QLabel *label_10;
    QGroupBox *groupBox_Velocity_2;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_Turn_Kp;
    QGroupBox *groupBox_Other;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_Other;
    QHBoxLayout *horizontalLayout_PWMlim;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_PWMlim;
    QHBoxLayout *horizontalLayout_Med;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Med;
    QHBoxLayout *horizontalLayout_Anglelim;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_Anglelim;
    QHBoxLayout *horizontalLayout_Speed;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Speed;
    QGroupBox *groupBox;
    QListWidget *listWidget_History;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_DataBits;
    QTableWidget *tableWidget_Databits;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_SetHistoryPID;
    QPushButton *pushButton_SavePID;
    QPushButton *pushButton_RefreshPID;
    QPushButton *pushButton_SendPID;
    QWidget *waveform;
    QPushButton *pushButton_Wave;
    QChartView *widget_Wave;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_EB;
    QLabel *label_Yaw;
    QLabel *label_Roll;
    QLabel *label_EB;
    QLabel *label_Pitch;
    QLabel *label_EA;
    QCheckBox *checkBox_Roll;
    QCheckBox *checkBox_Yaw;
    QCheckBox *checkBox_EA;
    QCheckBox *checkBox_Pitch;

    void setupUi(QWidget *PID)
    {
        if (PID->objectName().isEmpty())
            PID->setObjectName(QString::fromUtf8("PID"));
        PID->resize(1010, 580);
        PID->setMinimumSize(QSize(1010, 580));
        PID->setMaximumSize(QSize(1010, 580));
        tabWidget = new QTabWidget(PID);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1011, 581));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        paramters = new QWidget();
        paramters->setObjectName(QString::fromUtf8("paramters"));
        groupBox_Stand = new QGroupBox(paramters);
        groupBox_Stand->setObjectName(QString::fromUtf8("groupBox_Stand"));
        groupBox_Stand->setGeometry(QRect(0, 0, 241, 151));
        groupBox_Stand->setFont(font);
        layoutWidget = new QWidget(groupBox_Stand);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 231, 118));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_Vertical_Kd = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_Vertical_Kd->setObjectName(QString::fromUtf8("doubleSpinBox_Vertical_Kd"));
        doubleSpinBox_Vertical_Kd->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Vertical_Kd->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(doubleSpinBox_Vertical_Kd, 2, 1, 1, 1);

        doubleSpinBox_Vertical_Kp = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_Vertical_Kp->setObjectName(QString::fromUtf8("doubleSpinBox_Vertical_Kp"));
        doubleSpinBox_Vertical_Kp->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Vertical_Kp->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(doubleSpinBox_Vertical_Kp, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 40));
        label_7->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(10);
        label_7->setFont(font1);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 40));
        label_8->setMaximumSize(QSize(16777215, 40));
        label_8->setFont(font1);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        groupBox_Velocity = new QGroupBox(paramters);
        groupBox_Velocity->setObjectName(QString::fromUtf8("groupBox_Velocity"));
        groupBox_Velocity->setGeometry(QRect(0, 140, 241, 151));
        groupBox_Velocity->setFont(font);
        layoutWidget_2 = new QWidget(groupBox_Velocity);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 231, 118));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 40));
        label_9->setMaximumSize(QSize(16777215, 40));
        label_9->setFont(font1);

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        doubleSpinBox_Velocity_Kp = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_Velocity_Kp->setObjectName(QString::fromUtf8("doubleSpinBox_Velocity_Kp"));
        doubleSpinBox_Velocity_Kp->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Velocity_Kp->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(doubleSpinBox_Velocity_Kp, 0, 1, 1, 1);

        doubleSpinBox_Velocity_Ki = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_Velocity_Ki->setObjectName(QString::fromUtf8("doubleSpinBox_Velocity_Ki"));
        doubleSpinBox_Velocity_Ki->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Velocity_Ki->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(doubleSpinBox_Velocity_Ki, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(0, 40));
        label_10->setMaximumSize(QSize(16777215, 40));
        label_10->setFont(font1);

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        groupBox_Velocity_2 = new QGroupBox(paramters);
        groupBox_Velocity_2->setObjectName(QString::fromUtf8("groupBox_Velocity_2"));
        groupBox_Velocity_2->setGeometry(QRect(0, 280, 241, 111));
        groupBox_Velocity_2->setFont(font);
        layoutWidget_3 = new QWidget(groupBox_Velocity_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 50, 231, 54));
        gridLayout_3 = new QGridLayout(layoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 40));
        label_11->setMaximumSize(QSize(16777215, 40));
        label_11->setFont(font1);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        doubleSpinBox_Turn_Kp = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_Turn_Kp->setObjectName(QString::fromUtf8("doubleSpinBox_Turn_Kp"));
        doubleSpinBox_Turn_Kp->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Turn_Kp->setMaximumSize(QSize(16777215, 40));

        gridLayout_3->addWidget(doubleSpinBox_Turn_Kp, 0, 1, 1, 1);

        groupBox_Other = new QGroupBox(paramters);
        groupBox_Other->setObjectName(QString::fromUtf8("groupBox_Other"));
        groupBox_Other->setGeometry(QRect(250, 0, 281, 391));
        groupBox_Other->setFont(font);
        layoutWidget1 = new QWidget(groupBox_Other);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(4, 30, 271, 351));
        verticalLayout_Other = new QVBoxLayout(layoutWidget1);
        verticalLayout_Other->setObjectName(QString::fromUtf8("verticalLayout_Other"));
        verticalLayout_Other->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_PWMlim = new QHBoxLayout();
        horizontalLayout_PWMlim->setObjectName(QString::fromUtf8("horizontalLayout_PWMlim"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 40));
        label->setFont(font1);

        horizontalLayout_PWMlim->addWidget(label);

        doubleSpinBox_PWMlim = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_PWMlim->setObjectName(QString::fromUtf8("doubleSpinBox_PWMlim"));
        doubleSpinBox_PWMlim->setMinimumSize(QSize(0, 40));
        doubleSpinBox_PWMlim->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_PWMlim->addWidget(doubleSpinBox_PWMlim);


        verticalLayout_Other->addLayout(horizontalLayout_PWMlim);

        horizontalLayout_Med = new QHBoxLayout();
        horizontalLayout_Med->setObjectName(QString::fromUtf8("horizontalLayout_Med"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 40));
        label_2->setMaximumSize(QSize(16777215, 40));
        label_2->setFont(font1);

        horizontalLayout_Med->addWidget(label_2);

        doubleSpinBox_Med = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_Med->setObjectName(QString::fromUtf8("doubleSpinBox_Med"));
        doubleSpinBox_Med->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Med->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_Med->addWidget(doubleSpinBox_Med);


        verticalLayout_Other->addLayout(horizontalLayout_Med);

        horizontalLayout_Anglelim = new QHBoxLayout();
        horizontalLayout_Anglelim->setObjectName(QString::fromUtf8("horizontalLayout_Anglelim"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 40));
        label_3->setFont(font1);

        horizontalLayout_Anglelim->addWidget(label_3);

        doubleSpinBox_Anglelim = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_Anglelim->setObjectName(QString::fromUtf8("doubleSpinBox_Anglelim"));
        doubleSpinBox_Anglelim->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Anglelim->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_Anglelim->addWidget(doubleSpinBox_Anglelim);


        verticalLayout_Other->addLayout(horizontalLayout_Anglelim);

        horizontalLayout_Speed = new QHBoxLayout();
        horizontalLayout_Speed->setObjectName(QString::fromUtf8("horizontalLayout_Speed"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 40));
        label_4->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_Speed->addWidget(label_4);

        doubleSpinBox_Speed = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_Speed->setObjectName(QString::fromUtf8("doubleSpinBox_Speed"));
        doubleSpinBox_Speed->setMinimumSize(QSize(0, 40));
        doubleSpinBox_Speed->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_Speed->addWidget(doubleSpinBox_Speed);


        verticalLayout_Other->addLayout(horizontalLayout_Speed);

        groupBox = new QGroupBox(paramters);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(540, 0, 461, 241));
        groupBox->setFont(font);
        listWidget_History = new QListWidget(groupBox);
        listWidget_History->setObjectName(QString::fromUtf8("listWidget_History"));
        listWidget_History->setGeometry(QRect(10, 40, 441, 191));
        listWidget_History->setFont(font);
        groupBox_2 = new QGroupBox(paramters);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 380, 1001, 131));
        groupBox_2->setFont(font);
        lineEdit_DataBits = new QLineEdit(groupBox_2);
        lineEdit_DataBits->setObjectName(QString::fromUtf8("lineEdit_DataBits"));
        lineEdit_DataBits->setGeometry(QRect(10, 90, 981, 41));
        QFont font2;
        font2.setPointSize(9);
        lineEdit_DataBits->setFont(font2);
        tableWidget_Databits = new QTableWidget(groupBox_2);
        if (tableWidget_Databits->columnCount() < 15)
            tableWidget_Databits->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_Databits->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        if (tableWidget_Databits->rowCount() < 1)
            tableWidget_Databits->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_Databits->setVerticalHeaderItem(0, __qtablewidgetitem15);
        tableWidget_Databits->setObjectName(QString::fromUtf8("tableWidget_Databits"));
        tableWidget_Databits->setGeometry(QRect(10, 40, 981, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI Light"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        tableWidget_Databits->setFont(font3);
        tableWidget_Databits->setLayoutDirection(Qt::LeftToRight);
        tableWidget_Databits->setAutoFillBackground(false);
        tableWidget_Databits->setRowCount(1);
        tableWidget_Databits->setColumnCount(15);
        tableWidget_Databits->horizontalHeader()->setVisible(false);
        tableWidget_Databits->horizontalHeader()->setMinimumSectionSize(65);
        tableWidget_Databits->horizontalHeader()->setDefaultSectionSize(65);
        tableWidget_Databits->verticalHeader()->setVisible(false);
        tableWidget_Databits->verticalHeader()->setMinimumSectionSize(40);
        tableWidget_Databits->verticalHeader()->setDefaultSectionSize(40);
        widget = new QWidget(paramters);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(540, 260, 451, 138));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_SetHistoryPID = new QPushButton(widget);
        pushButton_SetHistoryPID->setObjectName(QString::fromUtf8("pushButton_SetHistoryPID"));
        pushButton_SetHistoryPID->setMinimumSize(QSize(0, 40));
        pushButton_SetHistoryPID->setMaximumSize(QSize(16777215, 40));
        pushButton_SetHistoryPID->setFont(font);

        gridLayout_5->addWidget(pushButton_SetHistoryPID, 1, 0, 1, 1);

        pushButton_SavePID = new QPushButton(widget);
        pushButton_SavePID->setObjectName(QString::fromUtf8("pushButton_SavePID"));
        pushButton_SavePID->setMinimumSize(QSize(0, 40));
        pushButton_SavePID->setMaximumSize(QSize(16777215, 40));
        pushButton_SavePID->setFont(font);

        gridLayout_5->addWidget(pushButton_SavePID, 0, 0, 1, 1);

        pushButton_RefreshPID = new QPushButton(widget);
        pushButton_RefreshPID->setObjectName(QString::fromUtf8("pushButton_RefreshPID"));
        pushButton_RefreshPID->setMinimumSize(QSize(0, 40));
        pushButton_RefreshPID->setMaximumSize(QSize(16777215, 40));
        pushButton_RefreshPID->setFont(font);

        gridLayout_5->addWidget(pushButton_RefreshPID, 0, 1, 1, 1);

        pushButton_SendPID = new QPushButton(widget);
        pushButton_SendPID->setObjectName(QString::fromUtf8("pushButton_SendPID"));
        pushButton_SendPID->setMinimumSize(QSize(0, 40));
        pushButton_SendPID->setMaximumSize(QSize(16777215, 40));
        pushButton_SendPID->setFont(font);

        gridLayout_5->addWidget(pushButton_SendPID, 1, 1, 1, 1);

        tabWidget->addTab(paramters, QString());
        waveform = new QWidget();
        waveform->setObjectName(QString::fromUtf8("waveform"));
        pushButton_Wave = new QPushButton(waveform);
        pushButton_Wave->setObjectName(QString::fromUtf8("pushButton_Wave"));
        pushButton_Wave->setGeometry(QRect(750, 330, 241, 54));
        pushButton_Wave->setFont(font1);
        widget_Wave = new QChartView(waveform);
        widget_Wave->setObjectName(QString::fromUtf8("widget_Wave"));
        widget_Wave->setGeometry(QRect(0, 0, 741, 521));
        layoutWidget2 = new QWidget(waveform);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(750, 0, 251, 324));
        gridLayout_4 = new QGridLayout(layoutWidget2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(6);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBox_EB = new QCheckBox(layoutWidget2);
        checkBox_EB->setObjectName(QString::fromUtf8("checkBox_EB"));
        checkBox_EB->setMinimumSize(QSize(0, 40));
        checkBox_EB->setMaximumSize(QSize(16777215, 40));
        checkBox_EB->setFont(font);

        gridLayout_4->addWidget(checkBox_EB, 4, 0, 1, 1);

        label_Yaw = new QLabel(layoutWidget2);
        label_Yaw->setObjectName(QString::fromUtf8("label_Yaw"));
        label_Yaw->setMinimumSize(QSize(0, 40));
        label_Yaw->setMaximumSize(QSize(16777215, 40));
        label_Yaw->setFont(font);

        gridLayout_4->addWidget(label_Yaw, 2, 1, 1, 1);

        label_Roll = new QLabel(layoutWidget2);
        label_Roll->setObjectName(QString::fromUtf8("label_Roll"));
        label_Roll->setMinimumSize(QSize(0, 40));
        label_Roll->setMaximumSize(QSize(16777215, 40));
        label_Roll->setFont(font);

        gridLayout_4->addWidget(label_Roll, 1, 1, 1, 1);

        label_EB = new QLabel(layoutWidget2);
        label_EB->setObjectName(QString::fromUtf8("label_EB"));
        label_EB->setMinimumSize(QSize(0, 40));
        label_EB->setMaximumSize(QSize(16777215, 40));
        label_EB->setFont(font);

        gridLayout_4->addWidget(label_EB, 4, 1, 1, 1);

        label_Pitch = new QLabel(layoutWidget2);
        label_Pitch->setObjectName(QString::fromUtf8("label_Pitch"));
        label_Pitch->setMinimumSize(QSize(0, 40));
        label_Pitch->setMaximumSize(QSize(16777215, 40));
        label_Pitch->setFont(font);

        gridLayout_4->addWidget(label_Pitch, 0, 1, 1, 1);

        label_EA = new QLabel(layoutWidget2);
        label_EA->setObjectName(QString::fromUtf8("label_EA"));
        label_EA->setMinimumSize(QSize(0, 40));
        label_EA->setMaximumSize(QSize(16777215, 40));
        label_EA->setFont(font);

        gridLayout_4->addWidget(label_EA, 3, 1, 1, 1);

        checkBox_Roll = new QCheckBox(layoutWidget2);
        checkBox_Roll->setObjectName(QString::fromUtf8("checkBox_Roll"));
        checkBox_Roll->setMinimumSize(QSize(0, 40));
        checkBox_Roll->setMaximumSize(QSize(16777215, 40));
        checkBox_Roll->setFont(font);

        gridLayout_4->addWidget(checkBox_Roll, 1, 0, 1, 1);

        checkBox_Yaw = new QCheckBox(layoutWidget2);
        checkBox_Yaw->setObjectName(QString::fromUtf8("checkBox_Yaw"));
        checkBox_Yaw->setMinimumSize(QSize(0, 40));
        checkBox_Yaw->setMaximumSize(QSize(16777215, 40));
        checkBox_Yaw->setFont(font);

        gridLayout_4->addWidget(checkBox_Yaw, 2, 0, 1, 1);

        checkBox_EA = new QCheckBox(layoutWidget2);
        checkBox_EA->setObjectName(QString::fromUtf8("checkBox_EA"));
        checkBox_EA->setMinimumSize(QSize(0, 40));
        checkBox_EA->setMaximumSize(QSize(16777215, 40));
        checkBox_EA->setFont(font);

        gridLayout_4->addWidget(checkBox_EA, 3, 0, 1, 1);

        checkBox_Pitch = new QCheckBox(layoutWidget2);
        checkBox_Pitch->setObjectName(QString::fromUtf8("checkBox_Pitch"));
        checkBox_Pitch->setMinimumSize(QSize(0, 40));
        checkBox_Pitch->setMaximumSize(QSize(16777215, 40));
        checkBox_Pitch->setFont(font);

        gridLayout_4->addWidget(checkBox_Pitch, 0, 0, 1, 1);

        tabWidget->addTab(waveform, QString());

        retranslateUi(PID);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PID);
    } // setupUi

    void retranslateUi(QWidget *PID)
    {
        PID->setWindowTitle(QApplication::translate("PID", "Form", nullptr));
        groupBox_Stand->setTitle(QApplication::translate("PID", "\347\233\264\347\253\213\347\216\257", nullptr));
        label_7->setText(QApplication::translate("PID", "Kp", nullptr));
        label_8->setText(QApplication::translate("PID", "Kd", nullptr));
        groupBox_Velocity->setTitle(QApplication::translate("PID", "\351\200\237\345\272\246\347\216\257", nullptr));
        label_9->setText(QApplication::translate("PID", "Kp", nullptr));
        label_10->setText(QApplication::translate("PID", "Ki", nullptr));
        groupBox_Velocity_2->setTitle(QApplication::translate("PID", "\350\275\254\345\220\221\347\216\257", nullptr));
        label_11->setText(QApplication::translate("PID", "Kp", nullptr));
        groupBox_Other->setTitle(QApplication::translate("PID", "\345\205\266\344\273\226\345\217\202\346\225\260", nullptr));
        label->setText(QApplication::translate("PID", "\351\231\220\345\271\205", nullptr));
        label_2->setText(QApplication::translate("PID", "\346\234\272\346\242\260\344\270\255\345\200\274", nullptr));
        label_3->setText(QApplication::translate("PID", "\351\231\220\350\247\222", nullptr));
        label_4->setText(QApplication::translate("PID", "\346\234\237\346\234\233\351\200\237\345\272\246", nullptr));
        groupBox->setTitle(QApplication::translate("PID", "\345\216\206\345\217\262\345\217\202\346\225\260", nullptr));
        groupBox_2->setTitle(QApplication::translate("PID", "\346\225\260\346\215\256\345\270\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Databits->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PID", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Databits->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PID", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Databits->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PID", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Databits->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PID", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Databits->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("PID", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Databits->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("PID", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Databits->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("PID", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Databits->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("PID", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Databits->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("PID", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Databits->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("PID", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Databits->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("PID", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Databits->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("PID", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Databits->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("PID", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_Databits->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("PID", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_Databits->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("PID", "15", nullptr));
        pushButton_SetHistoryPID->setText(QApplication::translate("PID", "\350\275\254\345\210\260\345\216\206\345\217\262", nullptr));
        pushButton_SavePID->setText(QApplication::translate("PID", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        pushButton_RefreshPID->setText(QApplication::translate("PID", "\346\233\264\346\226\260\346\225\260\346\215\256\345\270\247", nullptr));
        pushButton_SendPID->setText(QApplication::translate("PID", "\345\217\221\351\200\201\345\210\260\344\270\262\345\217\243", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(paramters), QApplication::translate("PID", "Tab 1", nullptr));
#ifndef QT_NO_TOOLTIP
        waveform->setToolTip(QApplication::translate("PID", "<html><head/><body><p>waveform</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Wave->setText(QApplication::translate("PID", "\346\230\276\347\244\272\346\263\242\345\275\242", nullptr));
        checkBox_EB->setText(QApplication::translate("PID", "\347\274\226\347\240\201\345\231\250B", nullptr));
        label_Yaw->setText(QApplication::translate("PID", "0", nullptr));
        label_Roll->setText(QApplication::translate("PID", "0", nullptr));
        label_EB->setText(QApplication::translate("PID", "0", nullptr));
        label_Pitch->setText(QApplication::translate("PID", "0", nullptr));
        label_EA->setText(QApplication::translate("PID", "0", nullptr));
        checkBox_Roll->setText(QApplication::translate("PID", "\346\273\232\351\231\215\350\247\222", nullptr));
        checkBox_Yaw->setText(QApplication::translate("PID", "\345\201\217\350\210\252\350\247\222", nullptr));
        checkBox_EA->setText(QApplication::translate("PID", "\347\274\226\347\240\201\345\231\250A", nullptr));
        checkBox_Pitch->setText(QApplication::translate("PID", "\344\277\257\344\273\260\350\247\222", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(waveform), QApplication::translate("PID", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PID: public Ui_PID {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PID_H
