#include "serialport.h"
#include "ui_serialport.h"

QSerialPort *serial = new QSerialPort; // 创建对象

char WaveFlag = '\0'; // 显示波形标志位

RecvFromSerial rfs;

Serialport::Serialport(QWidget *parent) : 
    QWidget(parent),
    ui(new Ui::Serialport)
{
    ui->setupUi(this);

    // log：使用成员变量，而不是重定义QTimer *timer = new QTimer(this);这样会导致内存泄露
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Serialport::handleTimeout); // 连接定时器的timeout信号到槽函数

    // 查找可用串口
    on_pushButton_SearchSerialport_clicked();

    // 设置默认串口COM12
    ui->comboBox_SerialPort->setCurrentIndex(2);

    // 设置默认数据位8
    ui->comboBox_DataBit->setCurrentIndex(3);

    // 连接信号和槽
    // log：connect函数第一个参数是QSerialPort*， 不需要加引用&
    connect(serial, &QSerialPort::readyRead, this, &Serialport::serialPort_readyRead);

    // 连接输入文本改变信号->文本改变槽函数
    // log：有点问题
    connect(ui->sendTextEdit, &QPlainTextEdit::textChanged, this, &Serialport::sendTextEditChanged);
}

void Serialport::handleTimeout()
{
    // 从接收缓冲区中读取数据，并添加到之前的缓冲区
    buffer.append(serial->readAll());

    //    qDebug() << "缓冲区" << buffer.toHex().toUpper();

    // 解析帧头帧尾
    QByteArray frameHeader = "\r\r";
    QByteArray frameFooter = "\n\n";
    // 检查是否存在完整的帧
    if (buffer.contains(frameHeader) && buffer.contains(frameFooter))
    {

        //        qDebug() << "存在帧头帧尾";

        // 提取帧数据
        int startIdx = buffer.indexOf(frameHeader);
        int endIdx = buffer.indexOf(frameFooter) + 2; // 包含帧尾

        //        qDebug() << "帧头" << startIdx;
        //        qDebug() << "帧尾" << endIdx;

        // 检测是否构成单个帧
        if (endIdx - startIdx != 20)
        {
            buffer.remove(0, endIdx); // 清除错误数据
            return;
        }

        //        qDebug() << "存在完整的帧";

        QByteArray frameData = buffer.mid(startIdx, endIdx - startIdx); // 第一位为起始索引，第二位为字符串长度
        //        qDebug() << frameData.toHex().toUpper();

        // 处理帧数据
        // frameData.mid(0, 1) = '\r';
        // frameData.mid(1, 4) = float Pitch;
        // frameData.mid(5, 4) = float Roll;
        // frameData.mid(9, 4) = float Yaw;
        // frameData.mid(13, 2) = int16_t EA;
        // frameData.mid(15, 2) = int16_t EB;
        // frameData.mid(17, 1) = '\n';

        //        //联合体自动处理帧数据
        //        union RecvFromSerial{
        //            char charArray[16];
        //            struct{
        //                float Pitch;
        //                float Roll;
        //                float Yaw;
        //                int16_t EA;
        //                int16_t EB;
        //            }stc;
        //        }rfs;

        for (size_t i = 0; i < sizeof(rfs); ++i)
        {
            rfs.charArray[i] = frameData[i + 2]; // 帧头占2位
        }

        QString sensorData = QString{"Pitch = %1, Roll = %2, Yaw = %3, EA = %4, EB = %5"}
                                 .arg(rfs.stc.Pitch, 0, 'f', 4)
                                 .arg(rfs.stc.Roll, 0, 'f', 4)
                                 .arg(rfs.stc.Yaw, 0, 'f', 4)
                                 .arg(rfs.stc.EA)
                                 .arg(rfs.stc.EB);

        // 添加到串口接收栏
        //        ui->receiveTextEdit->appendPlainText(sensorData);

        // 从 buffer 中移除已处理的帧数据
        buffer.remove(0, endIdx);
    }
}

/* 串口接收 槽函数 */
void Serialport::serialPort_readyRead()
{
    // 若为显示波形模式
    if (WaveFlag == '\1')
    {
        // 若定时器未打开，开启定时器
        if (!timer->isActive())
            timer->start(20); // 20ms
    }
    // 串口接收
    else if (WaveFlag == '\0')
    {
        // 关闭定时器
        if (timer->isActive())
            timer->stop();

        // 从接收缓冲区中读取数据
        buffer = serial->readAll();
        // 字符串显示
        if (ui->checkBox_HexDisplay->checkState() == 0)
        {
            // 取第一位之后的字符串显示
            ui->receiveTextEdit->appendPlainText(buffer.mid(1).data());
        }
        else
        {
            // 将buffer转换为十六进制字符串并转换为大写
            QString hexStr = buffer.toHex().toUpper();

            QString strDis;
            for (int i = 0; i < hexStr.length(); i += 2)
            {
                // 每两个字符之间添加一个空格
                QString st = hexStr.mid(i, 2);
                strDis += st;
                strDis += " ";
            }
            ui->receiveTextEdit->appendPlainText(strDis);
        }
    }
}

/* 文本限制 槽函数 */
void Serialport::sendTextEditChanged()
{
    if (ui->checkBox_HexSend->checkState() == 2)
    {
        // 只能输入数字 字母 空格
        QRegExp regexp("^[a-fA-F0-9\\s]*");

        QString strText = ui->sendTextEdit->toPlainText();

        // log：注意如果不判断空字符串，在清除文本框时会反复进入第二个分支，
        // 导致m_symtext被赋值为空字符串甚至程序崩溃
        if (!strText.isEmpty() && regexp.exactMatch(strText))
        {
            m_symtext = strText;
        }
        else if (!strText.isEmpty() && !regexp.exactMatch(strText))
        {
            ui->sendTextEdit->clear();
            ui->sendTextEdit->appendPlainText(m_symtext);
        }
    }
}

/* 打开串口 槽函数 */
void Serialport::on_pushButton_Open_clicked()
{
    if (ui->pushButton_Open->text() == QString("打开串口"))
    {
        // 自定义函数配置串口
        serialPort_Config();

        // 打开串口
        if (!serial->open(QIODevice::ReadWrite))
        {
            // QMessageBox::about(NULL, "提示", "无法打开串口！");
            QMessageBox::critical(this, "提示", "串口打开失败");
            return;
        }
        else
        {
            QMessageBox::information(this, "提示", "串口打开成功");
        }

        // 下拉菜单控件失能
        ui->comboBox_SerialPort->setEnabled(false);
        ui->comboBox_BaudRate->setEnabled(false);
        ui->comboBox_DataBit->setEnabled(false);
        ui->comboBox_Pority->setEnabled(false);
        ui->comboBox_StopBit->setEnabled(false);

        // 发送按键使能
        ui->pushButton_Send->setEnabled(true);

        // 按钮文本变为关闭
        ui->pushButton_Open->setText("关闭串口");
    }
    else
    {
        // 关闭定时器
        if (timer->isActive())
            timer->stop();

        // 关闭串口
        serial->close();

        // 下拉菜单控件使能
        ui->comboBox_SerialPort->setEnabled(true);
        ui->comboBox_BaudRate->setEnabled(true);
        ui->comboBox_DataBit->setEnabled(true);
        ui->comboBox_Pority->setEnabled(true);
        ui->comboBox_StopBit->setEnabled(true);

        // 发送按键失能
        ui->pushButton_Send->setEnabled(false);

        // 按钮文本变为打开
        ui->pushButton_Open->setText("打开串口");
    }
}

/* 串口发送 槽函数 */
void Serialport::on_pushButton_Send_clicked()
{
    QByteArray data;
    if (ui->checkBox_HexSend->checkState() == 0)
    {
        // 获取界面上的数据并转换成纯文本，加上帧头0x00，帧尾0x0d 0x0a（STM32写的串口协议的包尾）
        data.append('\0'); // 不是"\0"
        data.append(ui->sendTextEdit->toPlainText().toUtf8());
        data.append("\r\n");
    }
    else
    {
        // 获取界面上的数据并转换成16进制，帧头帧尾自己加
        data = QByteArray::fromHex(ui->sendTextEdit->toPlainText().toLatin1());
    }
    if (serial->write(data) == -1)
    {
        QMessageBox::information(this, "提示", "发送失败");
        return;
    }
    QMessageBox::information(this, "提示", "发送成功");
}

/* 清除接收区 槽函数 */
void Serialport::on_pushButton_ClearRcv_clicked()
{
    buffer.clear();
    ui->receiveTextEdit->clear();
}

/* 清除发送区 槽函数 */
void Serialport::on_pushButton_ClearSend_clicked()
{
    ui->sendTextEdit->clear();
}

/* 配置串口 */
void Serialport::serialPort_Config()
{
    // 设置串口名
    serial->setPortName(ui->comboBox_SerialPort->currentText());

    // 设置波特率
    switch (ui->comboBox_BaudRate->currentIndex())
    {
    case 0:
        serial->setBaudRate(QSerialPort::Baud9600);
        break; // 9600
    case 1:
        serial->setBaudRate(QSerialPort::Baud19200);
        break; // 19200
    case 2:
        serial->setBaudRate(QSerialPort::Baud38400);
        break; // 38400
    case 3:
        serial->setBaudRate(QSerialPort::Baud57600);
        break; // 57600
    case 4:
        serial->setBaudRate(QSerialPort::Baud115200);
        break; // 115200
    default:
        break;
    }

    // 设置数据位
    switch (ui->comboBox_DataBit->currentIndex())
    {
    case 0:
        serial->setDataBits(QSerialPort::Data5);
        break; // 5
    case 1:
        serial->setDataBits(QSerialPort::Data6);
        break; // 6
    case 2:
        serial->setDataBits(QSerialPort::Data7);
        break; // 7
    case 3:
        serial->setDataBits(QSerialPort::Data8);
        break; // 8
    default:
        break;
    }

    // 设置奇偶校验
    switch (ui->comboBox_Pority->currentIndex())
    {
    case 0:
        serial->setParity(QSerialPort::NoParity);
        break; // 无
    case 1:
        serial->setParity(QSerialPort::OddParity);
        break; // 奇校验
    case 2:
        serial->setParity(QSerialPort::EvenParity);
        break; // 偶校验
    default:
        break;
    }

    // 设置停止位
    switch (ui->comboBox_StopBit->currentIndex())
    {
    case 0:
        serial->setStopBits(QSerialPort::OneStop);
        break; // 1位
    case 1:
        serial->setStopBits(QSerialPort::OneAndHalfStop);
        break; // 1.5位
    case 2:
        serial->setStopBits(QSerialPort::TwoStop);
        break; // 2位
    default:
        break;
    }

    // 设置流控制
    serial->setFlowControl(QSerialPort::NoFlowControl);
}

/* 寻找可用串口 槽函数 */
void Serialport::on_pushButton_SearchSerialport_clicked()
{
    ui->comboBox_SerialPort->clear();
    // 通过QSerialPortInfo查找可用串口
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_SerialPort->addItem(info.portName());
    }
}

/* 析构函数 */
Serialport::~Serialport()
{
    delete ui;
    if (serial->isOpen())
        serial->close();
    delete serial;
}
