#include <iostream>
using namespace std;
#include <fstream>
#include "NN.h"

#define DATASET "dataset.txt"
#define MODEL "model.txt"

int main()
{
    NN net(0.1, 1); //预训练参数取0.1
    net.generateDataset();
    net.trainNN(20);
    // net.saveModel();
    // net.readModel();

    float x1, x2;
    while(1)
    {
        cout << "请输入点的坐标x1 x2: ";
        cin >> x1 >> x2;
        cout << "Result: " << net.getResult(x1, x2) << endl;
        net.Show_Output();
    }

    return 0;
}
