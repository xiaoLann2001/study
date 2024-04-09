#include "pid.h"
#include "ui_pid.h"

PID::PID(QWidget *parent) : 
    QWidget(parent),
    ui(new Ui::PID)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    // 连接定时溢出和定时中断函数
    connect(timer, &QTimer::timeout, this, &PID::handleTimeout);

    // 设置各参数范围
    ui->doubleSpinBox_Vertical_Kp->setRange(-720, 720);
    ui->doubleSpinBox_Vertical_Kd->setRange(-3.2768, 3.2767);
    ui->doubleSpinBox_Velocity_Kp->setRange(-131.07, 131.07);
    ui->doubleSpinBox_Velocity_Ki->setRange(-131.07 * 0.005, 131.07 * 0.005);
    ui->doubleSpinBox_Turn_Kp->setRange(-32.768, 32.767);
    ui->doubleSpinBox_PWMlim->setRange(0, 1);
    ui->doubleSpinBox_Med->setRange(-12.8, 12.8);
    ui->doubleSpinBox_Anglelim->setRange(0, 255);
    ui->doubleSpinBox_Speed->setRange(-128, 127);

    // 绑定速度环Ki = Kp / 200
    void (QDoubleSpinBox::*spinSignal)(double) = &QDoubleSpinBox::valueChanged;
    connect(ui->doubleSpinBox_Velocity_Kp, spinSignal, [=](double kp)
            { ui->doubleSpinBox_Velocity_Ki->setValue(kp * 0.005); });

    // 设置步长
    ui->doubleSpinBox_Vertical_Kp->setSingleStep(1);
    ui->doubleSpinBox_Vertical_Kd->setSingleStep(0.1);
    ui->doubleSpinBox_Velocity_Kp->setSingleStep(0.1);
    ui->doubleSpinBox_Turn_Kp->setSingleStep(0.1);
    ui->doubleSpinBox_PWMlim->setSingleStep(0.1);
    ui->doubleSpinBox_Med->setSingleStep(0.1);
    ui->doubleSpinBox_Anglelim->setSingleStep(1);
    ui->doubleSpinBox_Speed->setSingleStep(1);

    // 设置各参数小数位数
    ui->doubleSpinBox_Vertical_Kp->setDecimals(0);
    ui->doubleSpinBox_Vertical_Kd->setDecimals(4);
    ui->doubleSpinBox_Velocity_Kp->setDecimals(4);
    ui->doubleSpinBox_Velocity_Ki->setDecimals(7);
    ui->doubleSpinBox_Turn_Kp->setDecimals(4);
    ui->doubleSpinBox_PWMlim->setDecimals(1);
    ui->doubleSpinBox_Med->setDecimals(1);
    ui->doubleSpinBox_Anglelim->setDecimals(0);
    ui->doubleSpinBox_Speed->setDecimals(0);

    // 设置默认值
    ui->doubleSpinBox_Vertical_Kp->setValue(0);
    ui->doubleSpinBox_Vertical_Kd->setValue(0);
    ui->doubleSpinBox_Velocity_Kp->setValue(0);
    ui->doubleSpinBox_PWMlim->setValue(0.8);
    ui->doubleSpinBox_Med->setValue(-2.5);
    ui->doubleSpinBox_Anglelim->setValue(30);
    ui->doubleSpinBox_Speed->setValue(0);
    ui->checkBox_Pitch->setChecked(true);
    ui->checkBox_EB->setChecked(true);

    // 波形图表初始化
    Chart_Init();

    // 参数文件初始化
    File_Init();

    // 设置QListWidget右键菜单可显示
    /*初始化一个包含两个Action(Delete和ClearAll)的菜单*/
    popMenu_In_ListWidget_ = new QMenu(this);
    action_Delete_In_ListWidget_ = new QAction(tr("Delete"), this);
    action_Clear_In_ListWidget_ = new QAction(tr("ClearAll"), this);
    popMenu_In_ListWidget_->addAction(action_Delete_In_ListWidget_);
    popMenu_In_ListWidget_->addAction(action_Clear_In_ListWidget_);

    /*重要：设置QListWidget的contextMenuPolicy属性，不然不能显示右键菜单*/
    ui->listWidget_History->setContextMenuPolicy(Qt::CustomContextMenu);

    // 连接信号与槽函数
    connect(ui->listWidget_History, &QListWidget::customContextMenuRequested, [=]()
            { popMenu_In_ListWidget_->exec(QCursor::pos()); });
    connect(this->action_Delete_In_ListWidget_, &QAction::triggered, this, &PID::onActionDelete);
    connect(this->action_Clear_In_ListWidget_, &QAction::triggered, this, &PID::onActionClear);
}

PID::~PID()
{
    delete ui;
    timer->stop();
    delete timer;
}

// 曲线设置初始化
void PID::Chart_Init()
{
    // 初始化QChart的实例
    chart = new QChart();

    // 初始化QSplineSeries的实例
    lineSeries_Pitch = new QSplineSeries();
    lineSeries_Roll = new QSplineSeries();
    lineSeries_Yaw = new QSplineSeries();
    lineSeries_EA = new QSplineSeries();
    lineSeries_EB = new QSplineSeries();

    // 设置曲线的名称
    lineSeries_Pitch->setName("俯仰角");
    lineSeries_Roll->setName("滚降角");
    lineSeries_Yaw->setName("偏航角");
    lineSeries_EA->setName("编码器A");
    lineSeries_EB->setName("编码器B");

    // 设置曲线颜色
    //    lineSeries->setColor(QColor(255, 80, 0, 255));

    // 把曲线添加到QChart的实例chart中
    chart->addSeries(lineSeries_Pitch);
    chart->addSeries(lineSeries_Roll);
    chart->addSeries(lineSeries_Yaw);
    chart->addSeries(lineSeries_EA);
    chart->addSeries(lineSeries_EB);

    // 初始化X轴、两个Y轴
    axisX = new QValueAxis();       // 时间
    axisY_Angle = new QValueAxis(); // 角度
    axisY_Speed = new QValueAxis(); // 速度

    // 设置坐标轴显示的范围
    int MAX_X = 500;
    axisX->setMin(0);
    axisX->setMax(MAX_X);
    axisY_Angle->setMin(-30);
    axisY_Angle->setMax(30);
    axisY_Speed->setMin(-30);
    axisY_Speed->setMax(30);

    // 设置坐标轴上的格点
    axisX->setTickCount(3);
    axisY_Angle->setTickCount(5);
    axisY_Speed->setTickCount(5);

    // 设置坐标轴显示的名称
    QFont font("Microsoft YaHei", 8, QFont::Normal); // 微软雅黑。字体大小8
    axisX->setTitleFont(font);
    axisY_Angle->setTitleFont(font);
    axisY_Speed->setTitleFont(font);
    //    axisX->setTitleText("X-时间");
    //    axisY->setTitleText("Y-角度");
    //    axisY->setTitleText("Y-速度");

    // 设置网格显示true，不显示false
    axisY_Angle->setGridLineVisible(true);

    // 下方：Qt::AlignBottom，左边：Qt::AlignLeft
    // 右边：Qt::AlignRight，上方：Qt::AlignTop
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY_Angle, Qt::AlignLeft);
    chart->addAxis(axisY_Speed, Qt::AlignRight);

    // 把曲线关联到坐标轴
    lineSeries_Pitch->attachAxis(axisX);
    lineSeries_Pitch->attachAxis(axisY_Angle);
    lineSeries_Roll->attachAxis(axisX);
    lineSeries_Roll->attachAxis(axisY_Angle);
    lineSeries_Yaw->attachAxis(axisX);
    lineSeries_Yaw->attachAxis(axisY_Angle);
    lineSeries_EA->attachAxis(axisX);
    lineSeries_EA->attachAxis(axisY_Speed);
    lineSeries_EB->attachAxis(axisX);
    lineSeries_EB->attachAxis(axisY_Speed);

    // 把chart显示到窗口上
    ui->widget_Wave->setChart(chart);
    // ui->widget_Wave->setRenderHint(QPainter::Antialiasing); // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
}

// 更新曲线函数
void PID::DrawLine()
{
    int MAX_X = 500;
    if (count > MAX_X)
    {
        // 当曲线上最早的点超出X轴的范围时，剔除最早的点，
        lineSeries_Pitch->removePoints(0, lineSeries_Pitch->count() - MAX_X);
        lineSeries_Roll->removePoints(0, lineSeries_Roll->count() - MAX_X);
        lineSeries_Yaw->removePoints(0, lineSeries_Yaw->count() - MAX_X);
        lineSeries_EA->removePoints(0, lineSeries_EA->count() - MAX_X);
        lineSeries_EB->removePoints(0, lineSeries_EB->count() - MAX_X);

        // 更新X轴的范围
        axisX->setMin(count - MAX_X);
        axisX->setMax(count);
        //        chart->axisX()->setMin(count - MAX_X);
        //        chart->axisX()->setMax(count);
    }
    else
    {
        axisX->setMin(0);
        axisX->setMax(MAX_X);
        //        chart->axisX()->setMin(0);
        //        chart->axisX()->setMax(MAX_X);
    }

    //判断是否显示
    if(ui->checkBox_Pitch->checkState() == 2) lineSeries_Pitch->show();
    else lineSeries_Pitch->hide();
    if(ui->checkBox_Roll->checkState() == 2) lineSeries_Roll->show();
    else lineSeries_Roll->hide();
    if(ui->checkBox_Yaw->checkState() == 2) lineSeries_Yaw->show();
    else lineSeries_Yaw->hide();
    if(ui->checkBox_EA->checkState() == 2) lineSeries_EA->show();
    else lineSeries_EA->hide();
    if(ui->checkBox_EB->checkState() == 2) lineSeries_EB->show();
    else lineSeries_EB->hide();

    // 增加新的点到曲线末端
    lineSeries_Pitch->append(count, rfs.stc.Pitch);
    lineSeries_Roll->append(count, rfs.stc.Roll);
    lineSeries_Yaw->append(count, rfs.stc.Yaw);
    lineSeries_EA->append(count, rfs.stc.EA);
    lineSeries_EB->append(count, rfs.stc.EB);

    //计数值（时间）增加
    count++;
}

// 参数文件初始化
void PID::File_Init()
{
    // 清空ListWidget_History的内容
    ui->listWidget_History->clear();

    // 创建 QFile 对象，同时指定要操作的文件
    // log：相对路径要放在release同级目录
    QFile file("parameters.csv");

    // 若文件不存在
    if (!file.exists())
    {
        // 对文件进行写操作
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        // 创建文件并添加title
        QString title = "直立环Kp,直立环Kd,速度环Kp,速度环Ki,转向环Kp,限幅,机械中值,限角,速度";
        out << title << endl;
        // log:先存入QString，否则会出现乱码
        //        out << "直立环Kp,直立环Kd,速度环Kp,速度环Ki,转向环Kp,限幅,机械中值,限角,速度" << endl;
        file.close();
    }
    // 若文件存在
    else
    {
        // 对文件进行读写操作
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::information(this, "提示", "初始化时文件打开失败");
            return;
        }
        // 若文件为空
        if (file.size() == 0)
        {
            QTextStream out(&file);
            // 添加title
            QString title = "直立环Kp,直立环Kd,速度环Kp,速度环Ki,转向环Kp,限幅,机械中值,限角,速度";
            out << title << endl;
            file.close();
        }
        else
        {
            QTextStream in(&file);
            // 一直读，直至读取失败
            while (!in.atEnd())
            {
                // 从文件中读取一个字符串
                QString line = in.readLine();
                ui->listWidget_History->addItem(line);
            }
            file.close();
        }
    }
}

// 定时中断函数
void PID::handleTimeout()
{
    ui->label_Pitch->setText(QString{"%1"}.arg(rfs.stc.Pitch, 0, 'f', 4));
    ui->label_Roll->setText(QString{"%1"}.arg(rfs.stc.Roll, 0, 'f', 4));
    ui->label_Yaw->setText(QString{"%1"}.arg(rfs.stc.Yaw, 0, 'f', 4));
    ui->label_EA->setText(QString{"%1"}.arg(rfs.stc.EA));
    ui->label_EB->setText(QString{"%1"}.arg(rfs.stc.EB));
    DrawLine();
}

// 更新数据帧
void PID::on_pushButton_RefreshPID_clicked()
{
    // 将double类型转为补码
    uint8_t MODE = 1;
    uint16_t Vertical_Kp = ui->doubleSpinBox_Vertical_Kp->value();
    uint16_t Vertical_Kd = ui->doubleSpinBox_Vertical_Kd->value() * 10000;
    uint16_t Velocity_Kp = ui->doubleSpinBox_Velocity_Kp->value() * 250;
    uint16_t Turn_Kp = ui->doubleSpinBox_Turn_Kp->value() * 1000;
    uint8_t PWMlim = ui->doubleSpinBox_PWMlim->value() * 10;
    uint8_t Med = ui->doubleSpinBox_Med->value() * 10;
    uint8_t Anglelim = ui->doubleSpinBox_Anglelim->value();
    uint8_t Speed = ui->doubleSpinBox_Speed->value();

    // 将补码添加到ByteArray
    dataBitsTable.clear();
    dataBitsTable.append(MODE);
    dataBitsTable.append(Vertical_Kp / 256);
    dataBitsTable.append(Vertical_Kp % 256);
    dataBitsTable.append(Vertical_Kd / 256);
    dataBitsTable.append(Vertical_Kd % 256);
    dataBitsTable.append(Velocity_Kp / 256);
    dataBitsTable.append(Velocity_Kp % 256);
    dataBitsTable.append(Turn_Kp / 256);
    dataBitsTable.append(Turn_Kp % 256);
    dataBitsTable.append(PWMlim);
    dataBitsTable.append(Med);
    dataBitsTable.append(Anglelim);
    dataBitsTable.append(Speed);
    dataBitsTable.append("\r");
    dataBitsTable.append("\n");

    // 将ByteArray转化为16进制字符串
    QString str = dataBitsTable.toHex().toUpper();

    // 将每个数据位添加到表格窗口
    for (int i = 0; i < dataBitsTable.length(); i++)
    {
        ui->tableWidget_Databits->setItem(0, i, new QTableWidgetItem(str.mid(i * 2, 2)));
    }

    // 更新到文本框
    ui->lineEdit_DataBits->setText(str);

}

/* 串口发送数据 */
void PID::on_pushButton_SendPID_clicked()
{
    //关闭波形
    if(ui->pushButton_Wave->text() == "关闭波形") on_pushButton_Wave_clicked();

    if (serial->write(dataBitsTable) == -1)
    {
        QMessageBox::information(this, "提示", "发送失败");
        return;
    }
    QMessageBox::information(this, "提示", "发送成功");

    //打开波形
    if(ui->pushButton_Wave->text() == "显示波形") on_pushButton_Wave_clicked();
}

void PID::on_pushButton_SavePID_clicked()
{
    QFile file("parameters.csv");

    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(this, "提示", "保存参数时文件打开失败");
        return;
    }
    QTextStream out(&file);
    out << ui->doubleSpinBox_Vertical_Kp->value() << ","
        << ui->doubleSpinBox_Vertical_Kd->value() << ","
        << ui->doubleSpinBox_Velocity_Kp->value() << ","
        << ui->doubleSpinBox_Velocity_Ki->value() << ","
        << ui->doubleSpinBox_Turn_Kp->value() << ","
        << ui->doubleSpinBox_PWMlim->value() << ","
        << ui->doubleSpinBox_Med->value() << ","
        << ui->doubleSpinBox_Anglelim->value() << ","
        << ui->doubleSpinBox_Speed->value() << endl;
    file.close();

    // 更新到历史
    File_Init();
}

void PID::on_pushButton_SetHistoryPID_clicked()
{
    //判断是否为有效数据
    if((ui->listWidget_History->currentItem() == NULL) || (ui->listWidget_History->currentRow() == 0))
    {
        QMessageBox::information(this, "提示", "未选中参数");
        return;
    }
    //取逗号分隔的字符串到列表
    QString str = ui->listWidget_History->currentItem()->text();
    QStringList strlist = str.split(",");

    //赋值给SpinBox
    QString str0 = strlist.at(0);
    QString str1 = strlist.at(1);
    QString str2 = strlist.at(2);
    QString str4 = strlist.at(4);
    QString str5 = strlist.at(5);
    QString str6 = strlist.at(6);
    QString str7 = strlist.at(7);
    QString str8 = strlist.at(8);

    ui->doubleSpinBox_Vertical_Kp->setValue(str0.toDouble());
    ui->doubleSpinBox_Vertical_Kd->setValue(str1.toDouble());
    ui->doubleSpinBox_Velocity_Kp->setValue(str2.toDouble());
    ui->doubleSpinBox_Turn_Kp->setValue(str4.toDouble());
    ui->doubleSpinBox_PWMlim->setValue(str5.toDouble());
    ui->doubleSpinBox_Med->setValue(str6.toDouble());
    ui->doubleSpinBox_Anglelim->setValue(str7.toDouble());
    ui->doubleSpinBox_Speed->setValue(str8.toDouble());
}

void PID::on_pushButton_Wave_clicked()
{
    if (ui->pushButton_Wave->text() == QString("显示波形"))
    {
        WaveFlag = '\1';        //进入波形显示模式，串口将处理单片机发来的数据帧
        QByteArray setMode2;
        setMode2.append('\2');
        setMode2.append("\r\n");
        serial->write(setMode2);    //设置单片机为传感器数据发送模式，发送特定数据帧到串口
        timer->start(20); // 20ms   //开启定时器读取串口解析到的数据
        ui->pushButton_Wave->setText("关闭波形");
    }
    else if (ui->pushButton_Wave->text() == QString("关闭波形"))
    {
        WaveFlag = '\0';
        QByteArray setMode0;
        setMode0.append('\0');
        setMode0.append("\r\n");
        serial->write(setMode0);
        timer->stop();
        ui->pushButton_Wave->setText("显示波形");
    }
}

void PID::onActionDelete()
{
    // 定位当前选中的Item
    int index = ui->listWidget_History->currentRow();
    QListWidgetItem *item = ui->listWidget_History->currentItem();

    if (index == 0) // 若选中title
    {
        QMessageBox::information(this, "提示", "请不要删除Title");
    }
    else
    {
        // 从列表中移除
        delete item;
        QFile file(FILENAME);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this, "提示", "删除时读取文件失败");
            return;
        }
        QTextStream in(&file);
        QStringList lines;
        while (!in.atEnd())
        {
            lines << in.readLine();
        }
        file.close();

        // 删除列表中对应行的字符串
        lines.removeAt(index);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
        {
            QMessageBox::information(this, "提示", "删除时写入文件失败");
            return;
        }
        QTextStream out(&file);
        // 遍历容器中的QString对象
        foreach (const QString &line, lines)
        {
            out << line << endl;
        }
        file.close();
    }
}

void PID::onActionClear()
{
    // 清空ListWidget
    ui->listWidget_History->clear();

    // 删除文件内容
    QFile file("parameters.csv");

    // 以重写方式打开
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QMessageBox::information(this, "提示", "清空列表失败");
        return;
    }
    file.close();

    File_Init(); // 添加title
    File_Init(); // 显示内容
}
