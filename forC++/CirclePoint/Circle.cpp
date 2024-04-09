#include "Circle.h"
#include <cmath>

void Circle::setR(double r)
{
    m_R = r;
    cout << "setRadius sucessfully" << endl;
}

void Circle::setP(double x, double y)
{
    m_P.setX(x);
    m_P.setY(y);
    cout << "setPoint sucessfully" << endl;
}

double Circle::getR()
{
    return m_R;
}

Point Circle::getP()
{
    return m_P;
}

string Circle::Compare(Point &p)
{
    double x, y, d2;
    x = p.getX();
    y = p.getY();
    d2 = (x - m_P.getX())*(x - m_P.getX()) + 
         (y - m_P.getY())*(y - m_P.getY());

    if( abs(d2 - m_R*m_R) <= 1.7976931348623157E-308)   //1.797...是Double最小值
    {                                                   //支持无理数
        return "On the Circle";
    }
    else if(d2 > m_R*m_R)
    {
        return "Out the Circle";
    }
    return "In the Circle";
}

Circle::Circle()
{
    cout << "调用构造函数Circle()" << endl; 
}


Circle::~Circle()
{
    cout << "调用析构函数~Circle()" << endl;
}
