#include <iostream>
using namespace std;

#include "Point.h"
#include "Circle.h"

#include <math.h>

int main()
{
    double offset = 0.0000000000000001; //偏差检验判断准确性
    
    //实例化
    Point p1(sqrt(2)/2 + offset, sqrt(2)/2);

    Circle c1;
    c1.setR(1);
    c1.setP(0 ,0);

    cout << "Result: " << c1.Compare(p1) << endl;

    return 0;
}