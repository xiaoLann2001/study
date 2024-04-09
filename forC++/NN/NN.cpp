#include "NN.h"
#include <fstream>
#include <cmath>
#include <random>
#define DATASET "dataset.txt"
#define MODEL "model.txt"

/* 初始化权重 */
NN::NN(float p, float l)
{
    this->w1 = p;
    this->w2 = p;
    this->w3 = p;
    this->w4 = p;
    this->w5 = p;
    this->w6 = p;
    this->w7 = p;
    this->w8 = p;
    this->b1 = p;
    this->b2 = p;
    this->b3 = p;
    this->b4 = p;
    this->Eta = l;
}

/* 生成数据集,num表示生成的行数 */
void NN::generateDataset()
{
    ifstream ifs;
    ifs.open(DATASET, ios::in); // 以读的方式打开文件

    char ch;
    ifs >> ch;
    /* 若文件不存在或文件为空 */
    if ((!ifs.is_open()) || (ifs.eof()))
    {
        ifs.close();
        ofstream ofs;
        ofs.open(DATASET, ios::out); // 以写的方式打开文件

        /* 按照均匀分布产生0~1的1000个随机浮点数 */
        default_random_engine engine(time(NULL));
        uniform_real_distribution<float> r_distribution(0.0, 1.0);

        /* 将每个随机产生的数据x1,x2，和标注y1,y2写入文件 */
        float x1, x2, y1, y2;
        int count0 = 0;
        for (int i = 0; i < 1000; i++)
        {
            x1 = r_distribution(engine);
            x2 = r_distribution(engine);
            /* x1 + x2 <= 1 为区域0， x1 + x2 > 1 为区域1 */
            y1 = x1 + x2 <= 1 ? 0 : 1;
            y2 = 1 - y1;
            if (y1 == 0)
            {
                count0++;
            }

            ofs << x1 << " "
                << x2 << " "
                << y1 << " "
                << y2 << endl;
        }
        cout << "数据集生成成功！"
             << "共有1000组数据,其中有" << count0 << "个是区域0的点。" << endl;
        ofs.close();
    }
    else
    {
        ifstream ifs;
        ifs.open(DATASET, ios::in); // 以读的方式打开文件

        float x1, x2, y1, y2;
        int all = 0, count0 = 0;
        while (ifs >> x1 && ifs >> x2 && ifs >> y1 && ifs >> y2)
        {
            all++;
            if (y1 == 0)
            {
                count0++;
            }
        }
        cout << "已识别到数据集！"
             << "共有" << all << "组数据，其中有" << count0 << "个是区域0的点。" << endl;
        ifs.close();
    }
}

void NN::trainNN(int epoch)
{
    /* 训练epoch代 */
    for (int i = 0; i < epoch; i++)
    {
        ifstream ifs;
        ifs.open(DATASET, ios::in); // 读取数据集

        Layer input, mark; // 输入数据和标注数据

        /* 用数据集的前900行训练 */
        int index = 1;
        while ((ifs >> input.p1 && ifs >> input.p2 && ifs >> mark.p1 && ifs >> mark.p2) &&
               index <= 900)
        {
            /* 前向传播 */
            forwardPropagation(input);

            /* 计算损失 */
            Loss(mark);

            /* 反向传播 */
            backwardPropagation(mark);

            /* 更新参数 */
            upgradeParameters();

            index++;
        }

        index = 901;
        int probability = 0;
        /* 用数据集的后100行验证 */
        while ((ifs >> input.p1 && ifs >> input.p2 && ifs >> mark.p1 && ifs >> mark.p2) &&
               index <= 1000)
        {
            /* 判断结果是否正确，比较第一个是否为1 */
            if (getResult(input.p1, input.p2) == (int)mark.p1)
            {
                probability++;
            }
            /* 计算损失 */
            Loss(mark);
            index++;
        }

        /* 显示这一代最终结果 */
        cout << "epo:" << i
             << "\t   Loss:" << this->Error
             << "\t   Prob:" << probability << "%" << endl;

        ifs.close();
    }
}

/* 前向传播 */
void NN::forwardPropagation(Layer input)
{
    this->InputLayer.p1 = input.p1;
    this->InputLayer.p2 = input.p2;

    this->HiddenLayer.p1 = this->w1 * input.p1 + this->w3 * input.p2 + this->b1;
    this->HiddenLayer.p2 = this->w2 * input.p1 + this->w4 * input.p2 + this->b2;
    this->HiddenLayer.p1 = 1 / (1 + exp(-1 * this->HiddenLayer.p1));
    this->HiddenLayer.p2 = 1 / (1 + exp(-1 * this->HiddenLayer.p2));

    this->OutputLayer.p1 = this->w5 * this->HiddenLayer.p1 + this->w7 * this->HiddenLayer.p2 + b3;
    this->OutputLayer.p2 = this->w6 * this->HiddenLayer.p1 + this->w8 * this->HiddenLayer.p2 + b4;
    this->OutputLayer.p1 = 1 / (1 + exp(-1 * this->OutputLayer.p1));
    this->OutputLayer.p2 = 1 / (1 + exp(-1 * this->OutputLayer.p2));
}

/* 计算损失 */
void NN::Loss(Layer mark)
{
    this->Error = 0.5 * (pow((this->OutputLayer.p1 - mark.p1), 2) +
                         pow((this->OutputLayer.p2 - mark.p2), 2));
}

/* 反向传播 */
void NN::backwardPropagation(Layer mark)
{
    float sigmoidO1, sigmoidO2, sigmoidH1, sigmoidH2;
    sigmoidO1 = this->OutputLayer.p1 * (1 - this->OutputLayer.p1);
    sigmoidO2 = this->OutputLayer.p2 * (1 - this->OutputLayer.p2);
    sigmoidH1 = this->HiddenLayer.p1 * (1 - this->HiddenLayer.p1);
    sigmoidH2 = this->HiddenLayer.p2 * (1 - this->HiddenLayer.p2);

    this->d8 = (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->HiddenLayer.p2;
    this->d7 = (this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->HiddenLayer.p2;
    this->d6 = (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->HiddenLayer.p1;
    this->d5 = (this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->HiddenLayer.p1;

    this->d4 = ((this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->w7 +
                (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->w8) *
               sigmoidH2 * this->InputLayer.p2;
    this->d3 = ((this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->w5 +
                (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->w6) *
               sigmoidH1 * this->InputLayer.p2;
    this->d2 = ((this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->w7 +
                (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->w8) *
               sigmoidH2 * this->InputLayer.p1;
    this->d1 = ((this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->w5 +
                (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->w6) *
               sigmoidH1 * this->InputLayer.p1;

    this->db4 = (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * 1;
    this->db3 = (this->OutputLayer.p1 - mark.p1) * sigmoidO1 * 1;
    this->db2 = ((this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->w7 +
                 (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->w8) *
                sigmoidH2 * 1;
    this->db1 = ((this->OutputLayer.p1 - mark.p1) * sigmoidO1 * this->w5 +
                 (this->OutputLayer.p2 - mark.p2) * sigmoidO2 * this->w6) *
                sigmoidH1 * 1;
}

/* 更新参数 */
void NN::upgradeParameters()
{
    w1 -= this->Eta * d1;
    w2 -= this->Eta * d2;
    w3 -= this->Eta * d3;
    w4 -= this->Eta * d4;
    w5 -= this->Eta * d5;
    w6 -= this->Eta * d6;
    w7 -= this->Eta * d7;
    w8 -= this->Eta * d8;
    b1 -= this->Eta * db1;
    b2 -= this->Eta * db2;
    b3 -= this->Eta * db3;
    b4 -= this->Eta * db4;
}

/* 模型推理，返回0则为区域0，返回1则为区域1 */
int NN::getResult(float x1, float x2)
{
    Layer x;
    x.p1 = x1;
    x.p2 = x2;
    this->forwardPropagation(x);
    if (this->OutputLayer.p1 <= this->OutputLayer.p2)
    {
        return 0;
    }
    return 1;
}

/* 显示输出层数据 */
void NN::Show_Output()
{
    cout << "O1: " << this->OutputLayer.p1 << "   O2: " << this->OutputLayer.p2 << endl;
}

/* 保存模型参数 */
void NN::saveModel()
{
    ofstream ofs;
    ofs.open(MODEL, ios::out); // 以写的方式打开文件

    ofs << this->w1 << " "
        << this->w2 << " "
        << this->w3 << " "
        << this->w4 << " "
        << this->w5 << " "
        << this->w6 << " "
        << this->w7 << " "
        << this->w8 << " "
        << this->b1 << " "
        << this->b2 << " "
        << this->b3 << " "
        << this->b4 << endl;

    cout << "成功保存模型！" << endl;
    ofs.close();
}

/* 读取模型参数 */
void NN::readModel()
{
    ifstream ifs;
    ifs.open(MODEL, ios::in);

    ifs >> this->w1 >> this->w2 >> this->w3 >> this->w4 >> this->w5 >> this->w6 >> this->w7 >> this->w8 >> this->b1 >> this->b2 >> this->b3 >> this->b4;

    cout << "成功读取模型！" << endl;
    ifs.close();
}