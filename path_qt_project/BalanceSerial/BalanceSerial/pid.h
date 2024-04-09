#ifndef PID_H
#define PID_H

#include <QWidget>
#include "serialport.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QMessageBox>
#include <QDebug>
#include <QDoubleSpinBox>
#include <QTimer>
#include <QtCharts>
#include <QFile>
#include <QTextStream>

#define FILENAME "parameters.csv"

namespace Ui {
class PID;
}

class PID : public QWidget
{
    Q_OBJECT

public:
    explicit PID(QWidget *parent = nullptr);
    ~PID();

    //图表初始化函数
    void Chart_Init();

    //更新曲线函数
    void DrawLine();

    //参数文件初始化
    void File_Init();

private slots:
    void on_pushButton_RefreshPID_clicked();

    void on_pushButton_SendPID_clicked();

    void on_pushButton_SavePID_clicked();

    void on_pushButton_SetHistoryPID_clicked();

    void on_pushButton_Wave_clicked();

    void onActionDelete();

    void onActionClear();

    //定时器中断函数
    void handleTimeout();

private:
    Ui::PID *ui;

    //数据帧数组
    QByteArray dataBitsTable;

    //定时器
    QTimer *timer;

    //图表
    QChart *chart;

    //俯仰角曲线
    QSplineSeries *lineSeries_Pitch;
    QSplineSeries *lineSeries_Roll;
    QSplineSeries *lineSeries_Yaw;

    //速度（编码器）曲线
    QSplineSeries *lineSeries_EA;
    QSplineSeries *lineSeries_EB;

    //x轴，时间轴
    QValueAxis *axisX;

    //y轴角度轴
    QValueAxis *axisY_Angle;

    //y轴速度轴
    QValueAxis *axisY_Speed;

    //x轴数据数量
    int count;

    //右键菜单栏
    QMenu *popMenu_In_ListWidget_;
    //菜单栏选项
    QAction *action_Delete_In_ListWidget_;
    QAction *action_Clear_In_ListWidget_;
};

#endif // PID_H
