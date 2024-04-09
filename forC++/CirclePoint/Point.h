#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    Point();
    Point(double x, double y);
    Point(const Point &p);
    ~Point();

private:
    double m_X;
    double m_Y;
};