#include "control.h"
#include "ui_control.h"

Control::Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);

    // 创建定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Control::handleTimeout);

    // 设置定时器间隔
    timerInterval = 20; // 毫秒

    // 启动定时器
//    timer->start(timerInterval);

    // 设置窗口焦点策略，确保窗口能够接收键盘事件
    setFocusPolicy(Qt::StrongFocus);
}

Control::~Control()
{
    delete ui;
}

void Control::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())  // 检查是否为重复事件
    {
        // 屏蔽其他按键，添加当前按下的非修饰键到集合中
        if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
           event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
            pressedKeys.insert(event->key());

        //检测按下的按键
        switch (event->key())
        {
        case Qt::Key_Up:
            ui->pushButton_Move_forward->pressed();
            break;
        case Qt::Key_Down:
            ui->pushButton_Move_backward->pressed();
            break;
        case Qt::Key_Left:
            ui->pushButton_Turn_left->pressed();
            break;
        case Qt::Key_Right:
            ui->pushButton_Turn_right->pressed();
            break;
        case Qt::Key_Space:
            ui->pushButton_Stop->pressed();
            break;
        default:
            break;
        }
    }

    // 在这里处理其他按键事件
    // ...

    // 将事件传递给基类
    QWidget::keyPressEvent(event);
}

void Control::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())  // 检查是否为重复事件
    {
        //检测松开的按键
        switch (event->key())
        {
        case Qt::Key_Up:
            ui->pushButton_Move_forward->released();
            break;
        case Qt::Key_Down:
            ui->pushButton_Move_backward->released();
            break;
        case Qt::Key_Left:
            ui->pushButton_Turn_left->released();
            break;
        case Qt::Key_Right:
            ui->pushButton_Turn_right->released();
            break;
        case Qt::Key_Space:
            ui->pushButton_Stop->released();
            break;
        default:
            break;
        }
    }

    // 在这里处理其他按键释放事件
    // ...

    // 将事件传递给基类
    QWidget::keyReleaseEvent(event);
}

// 定时中断函数
void Control::handleTimeout()
{
    // 在定时器溢出时执行的操作
//    qDebug() << pressedKeys;
    // 执行你的操作...
    int8_t speed = 0;
    int8_t turn = 0;

    if(pressedKeys.contains(16777235) && !pressedKeys.contains(16777237))  //Qt::Key_Up
    {
        speed = 30; //前进
    }
    else if(!pressedKeys.contains(16777235) && pressedKeys.contains(16777237))  //Qt::Key_Down
    {
        speed = -30;//后退
    }

    if(pressedKeys.contains(16777234) && !pressedKeys.contains(16777236))  //Qt::Key_Left
    {
        turn = -100;  //左转，逆时针
    }
    else if(!pressedKeys.contains(16777234) && pressedKeys.contains(16777236))  //Qt::Key_Left
    {
        turn = 100;  //右转，顺时针
    }

    if(pressedKeys.contains(32))    //Qt::Key_Space 刹车
    {
        speed = 0;
        turn = 0;
    }

    QByteArray ctrlFrame;
    ctrlFrame.append(3);
    ctrlFrame.append(speed);
    ctrlFrame.append(turn);
    ctrlFrame.append("\r\n");

    qDebug() << ctrlFrame.toHex().toUpper();
    serial->write(ctrlFrame);
}

void Control::startTimerIfNotActive()
{
    if (!timer->isActive())
    {
        timer->start(timerInterval);
    }
}

void Control::stopTimerIfNoKeysPressed()
{
    if (pressedKeys.isEmpty() && timer->isActive())
    {
        timer->stop();

        int8_t speed = 0;
        int8_t turn = 0;
        QByteArray ctrlFrame;
        ctrlFrame.append(3);
        ctrlFrame.append(speed);
        ctrlFrame.append(turn);
        ctrlFrame.append("\r\n");
        qDebug() << "stop:" << ctrlFrame.toHex().toUpper();
        serial->write(ctrlFrame);
    }
}

void Control::on_pushButton_Move_forward_pressed()
{
    ui->pushButton_Move_forward->setStyleSheet("background-color: green;");
    qDebug() << "Move forward";
    pressedKeys.insert(Qt::Key_Up);
    startTimerIfNotActive();
}

void Control::on_pushButton_Move_backward_pressed()
{
    ui->pushButton_Move_backward->setStyleSheet("background-color: green;");
    qDebug() << "Move backward";
    pressedKeys.insert(Qt::Key_Down);
    startTimerIfNotActive();
}

void Control::on_pushButton_Turn_left_pressed()
{
    ui->pushButton_Turn_left->setStyleSheet("background-color: green;");
    qDebug() << "Turn left";
    pressedKeys.insert(Qt::Key_Left);
    startTimerIfNotActive();
}

void Control::on_pushButton_Turn_right_pressed()
{
    ui->pushButton_Turn_right->setStyleSheet("background-color: green;");
    qDebug() << "Turn right";
    pressedKeys.insert(Qt::Key_Right);
    startTimerIfNotActive();
}

void Control::on_pushButton_Stop_pressed()
{
    ui->pushButton_Stop->setStyleSheet("background-color: green;");
    qDebug() << "Stop";
    pressedKeys.insert(Qt::Key_Space);
    startTimerIfNotActive();
}

void Control::on_pushButton_Move_forward_released()
{
    ui->pushButton_Move_forward->setStyleSheet("");
    pressedKeys.remove(Qt::Key_Up);   //Qt::Key_Up
    stopTimerIfNoKeysPressed();
}

void Control::on_pushButton_Move_backward_released()
{
   ui->pushButton_Move_backward->setStyleSheet("");
   pressedKeys.remove(Qt::Key_Down);    //Qt::Key_Down
   stopTimerIfNoKeysPressed();
}

void Control::on_pushButton_Turn_left_released()
{
    ui->pushButton_Turn_left->setStyleSheet("");
    pressedKeys.remove(Qt::Key_Left);   //Qt::Key_Left
    stopTimerIfNoKeysPressed();
}

void Control::on_pushButton_Turn_right_released()
{
    ui->pushButton_Turn_right->setStyleSheet("");
    pressedKeys.remove(Qt::Key_Right);   //Qt::Key_Right
    stopTimerIfNoKeysPressed();
}

void Control::on_pushButton_Stop_released()
{
    ui->pushButton_Stop->setStyleSheet("");
    pressedKeys.remove(Qt::Key_Space);   //Qt::Key_Right
    stopTimerIfNoKeysPressed();
}
