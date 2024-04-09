#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QCoreApplication>
#include <QDebug>
#include "serialport.h"

namespace Ui {
class Control;
}

class Control : public QWidget
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = nullptr);
    ~Control();

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void handleTimeout();

    void startTimerIfNotActive();

    void stopTimerIfNoKeysPressed();

    void on_pushButton_Move_forward_pressed();

    void on_pushButton_Move_backward_pressed();

    void on_pushButton_Turn_left_pressed();

    void on_pushButton_Turn_right_pressed();

    void on_pushButton_Stop_pressed();

    void on_pushButton_Move_forward_released();

    void on_pushButton_Move_backward_released();

    void on_pushButton_Turn_left_released();

    void on_pushButton_Turn_right_released();

    void on_pushButton_Stop_released();

private:
    Ui::Control *ui;

    QTimer *timer;

    int timerInterval;

    QSet<int> pressedKeys; // 用于存储当前按下的非修饰键

};

#endif // CONTROL_H
