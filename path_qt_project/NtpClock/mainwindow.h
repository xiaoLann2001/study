#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "global.h"
#include "ntpclient.h"

#define WINDOWS_WIDTH 1024
#define WINDOWS_HEIGHT 600

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTime(qint64 secoffset, qint64 msecoffset);
    void timerHandle(void);
    void timing(void);

private:
    QDateTime datetime;

    Ui::MainWindow *ui;
    QPushButton *btn;

    NtpClient *ntpclient;
    QTimer *timer;
};

#endif // MAINWINDOW_H
