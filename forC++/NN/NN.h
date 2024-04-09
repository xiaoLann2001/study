#ifndef __NN_H_
#define __NN_H_
#include <iostream>
using namespace std;

struct Layer
{
    float p1;
    float p2;
};

class NN
{
private:
    /* 网络参数,w1-w4为输入层到隐藏层，w5-w8为隐藏层到输出层 */
    float w1, w2, w3, w4, w5, w6, w7, w8, b1, b2, b3, b4;

    /* 梯度 di = d(Error) / d(wi) */
    float d1, d2, d3, d4, d5, d6, d7, d8, db1, db2, db3, db4;

    /* 误差 Error = 0.5 * ((o1 - y1) ^ 2 + (o2 - y2) ^ 2) */
    float Error;

    /* 学习率 */
    float Eta;

    /* 输入层 */
    Layer InputLayer;

    /* 隐藏层 */
    Layer HiddenLayer;

    /* 输出层 */
    Layer OutputLayer;

public:
    NN(){};
    NN(float p, float l);
    
    /* 训练模型参数 */
    void trainNN(int epoch);

    /* 生成数据集 */
    void generateDataset();

    /* 前向传播 */
    void forwardPropagation(Layer input);

    /* 计算损失 */
    void Loss(Layer mark);

    /* 反向传播 */
    void backwardPropagation(Layer mark);

    /* 更新参数 */
    void upgradeParameters();

    /* 模型推理 */
    int getResult(float x1, float x2);

    /* 显示输出层数据 */
    void Show_Output();

    /* 保存模型参数 */
    void saveModel();

    /* 读取模型参数 */
    void readModel();
};

#endif
