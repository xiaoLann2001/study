#pragma once
#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(){m_X = 0; m_Y = 0; m_Z = 0;}
    Vector(double x, double y, double z);

    double getX();
    double getY();
    double getZ();

    Vector operator+(Vector &p);
    Vector operator+(double x);

    Vector operator-(Vector &p);
    Vector operator-(double x);

    double operator*(Vector &p);

private:
    double m_X;
    double m_Y;
    double m_Z;
};

ostream & operator<<(ostream &out , Vector &p);