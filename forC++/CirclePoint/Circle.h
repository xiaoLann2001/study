#pragma once
#include <iostream>
using namespace std;

#include "Point.h"

class Circle
{
    //成员:属性,行为
public:
    //行为、成员行为、成员函数
    void setR(double r);
    void setP(double x, double y);
    double getR();
    Point getP();
    string Compare(Point &p);
    Circle();
    ~Circle();

private:
    //属性、成员属性、成员变量
    double m_R;
    Point m_P;  
};