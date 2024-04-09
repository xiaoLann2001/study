#include "Point.h"

void Point::setX(double x)
{
    m_X = x;
}

void Point::setY(double y)
{
    m_Y = y;
}

double Point::getX()
{
    return m_X;
}

double Point::getY()
{
    return m_Y;
}

Point::Point()
{
    cout << "调用无参构造函数Point()" << endl; 
}

Point::Point(double x, double y)
{
    cout << "调用有参构造函数Point(int x, int y)" << endl; 
    m_X = x;
    m_Y = y;
}

Point::Point(const Point &p)
{
    cout << "调用拷贝构造函数Point(const Point &p)" << endl;
    m_X = p.m_X;
    m_Y = p.m_Y;
}

Point::~Point()
{
    cout << "调用析构函数~Point()" << endl;
}