#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>
#include <QString>
#include <QTimer>

extern QSerialPort *serial;
extern char WaveFlag;
extern union RecvFromSerial{//联合体自动处理帧数据
    char charArray[16];
    struct{
        float Pitch;
        float Roll;
        float Yaw;
        int16_t EA;
        int16_t EB;
    }stc;
}rfs;

namespace Ui {
class Serialport;
}

class Serialport : public QWidget
{
    Q_OBJECT

public:
    friend class PID;

    explicit Serialport(QWidget *parent = nullptr);
    ~Serialport();

    /* 接受显示 */
    void serialPort_readyRead();

    /* 配置串口 */
    void serialPort_Config();

    /* 发送格式 */
    void sendTextEditChanged();

private slots:
    void on_pushButton_Open_clicked();

    void on_pushButton_Send_clicked();

    void on_pushButton_ClearRcv_clicked();

    void on_pushButton_ClearSend_clicked();

    void on_pushButton_SearchSerialport_clicked();

    void handleTimeout();

private:
    Ui::Serialport *ui;

    QTimer *timer;

    //从接收缓冲区中读取数据
    QByteArray buffer;

    //格式限制文本
    QString m_symtext;
};

#endif // SERIALPORT_H
