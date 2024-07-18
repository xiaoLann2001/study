#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // datetime
    datetime = QDateTime::currentDateTime();
    QTimeZone timezone("Asia/Shanghai");
    datetime.setTimeZone(timezone);

    // ntp client
    ntpclient = new NtpClient(this);
    connect(ntpclient, &NtpClient::timeReceived, this, &MainWindow::updateTime);

    // timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerHandle);
    timing();
    timer->setInterval(50);
    timer->start();

    // ui
    ui->setupUi(this);

    btn = new QPushButton(this);
    btn->setGeometry(WINDOWS_WIDTH / 20 * 9, WINDOWS_HEIGHT * 2 / 3, WINDOWS_WIDTH / 10, WINDOWS_HEIGHT / 10);
    btn->setText("timing");
    connect(btn, &QPushButton::clicked, this, &MainWindow::timing);
}

void MainWindow::updateTime(qint64 secoffset, qint64 msecoffset)
{
    timer->stop();
    datetime = datetime.addSecs(secoffset).addMSecs(msecoffset);
    timer->start();
}

void MainWindow::timerHandle()
{
    ui->label_HMS->setText(datetime.time().toString());
    datetime = datetime.addMSecs(timer->interval());
    if (datetime.time().second() == 0)
        timing();
}

void MainWindow::timing()
{
    if (DEBUG)
        qDebug() << "timing";
    ntpclient->sendNtpRequest("ntp.tuna.tsinghua.edu.cn");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete btn;
    delete ntpclient;
}
