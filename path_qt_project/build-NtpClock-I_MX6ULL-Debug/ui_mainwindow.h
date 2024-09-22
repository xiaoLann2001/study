/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionexit;
    QWidget *centralWidget;
    QLabel *label_HMS;
    QMenuBar *menuBar;
    QMenu *menuNtpClock;
    QMenu *menuTimeZone;
    QMenu *menuStyle;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setMinimumSize(QSize(1024, 600));
        MainWindow->setMaximumSize(QSize(1024, 600));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_HMS = new QLabel(centralWidget);
        label_HMS->setObjectName(QString::fromUtf8("label_HMS"));
        label_HMS->setEnabled(true);
        label_HMS->setGeometry(QRect(0, 100, 1024, 160));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(120);
        font.setBold(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        label_HMS->setFont(font);
        label_HMS->setAlignment(Qt::AlignCenter);
        label_HMS->setWordWrap(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 17));
        menuNtpClock = new QMenu(menuBar);
        menuNtpClock->setObjectName(QString::fromUtf8("menuNtpClock"));
        menuTimeZone = new QMenu(menuBar);
        menuTimeZone->setObjectName(QString::fromUtf8("menuTimeZone"));
        menuStyle = new QMenu(menuBar);
        menuStyle->setObjectName(QString::fromUtf8("menuStyle"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(0, 24));
        toolBar->setMaximumSize(QSize(16777215, 24));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuNtpClock->menuAction());
        menuBar->addAction(menuTimeZone->menuAction());
        menuBar->addAction(menuStyle->menuAction());
        menuNtpClock->addAction(actionexit);

        retranslateUi(MainWindow);
        QObject::connect(actionexit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionexit->setText(QApplication::translate("MainWindow", "exit", nullptr));
        label_HMS->setText(QApplication::translate("MainWindow", "00:00:00", nullptr));
        menuNtpClock->setTitle(QApplication::translate("MainWindow", "NtpClock", nullptr));
        menuTimeZone->setTitle(QApplication::translate("MainWindow", "TimeZone", nullptr));
        menuStyle->setTitle(QApplication::translate("MainWindow", "Style", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
