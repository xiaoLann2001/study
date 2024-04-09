#include "Vector.h"

/*有参构造函数初始化成员变量*/
Vector::Vector(double x, double y, double z):m_X(x), m_Y(y), m_Z(z)
{

}

/*返回成员m_X的值*/
double Vector::getX()
{
    return m_X;
}

/*返回成员m_Y的值*/
double Vector::getY()
{
    return m_Y;
}

/*返回成员m_Z的值*/
double Vector::getZ()
{
    return m_Z;
}

/*打印向量*/
void showVector(Vector &p)
{
    cout<< "("
        << p.getX() << ","
        << p.getY() << ","
        << p.getZ() << ")";
}

/*运算符+重载,向量相加*/
Vector Vector::operator+(Vector &p)
{
    Vector temp;
    temp.m_X = this->m_X + p.m_X;
    temp.m_Y = this->m_Y + p.m_Y;
    temp.m_Z = this->m_Z + p.m_Z;
    return temp;
}

/*运算符+重载的函数重载,向量加实数*/
Vector Vector::operator+(double x)
{
    Vector temp;
    temp.m_X = this->m_X + x;
    temp.m_Y = this->m_Y + x;
    temp.m_Z = this->m_Z + x;
    return temp;
}

/*运算符-重载,向量相减*/
Vector Vector::operator-(Vector &p)
{
    Vector temp;
    temp.m_X = this->m_X - p.m_X;
    temp.m_Y = this->m_Y - p.m_Y;
    temp.m_Z = this->m_Z - p.m_Z;
    return temp;
}

/*运算符-重载的函数重载,向量减实数*/
Vector Vector::operator-(double x)
{
    Vector temp;
    temp.m_X = this->m_X - x;
    temp.m_Y = this->m_Y - x;
    temp.m_Z = this->m_Z - x;
    return temp;
}

/*运算符*重载,计算并返回向量内积*/
double Vector::operator*(Vector &p)
{
    return this->m_X * p.m_X
        + this->m_Y * p.m_Y
        + this->m_Z * p.m_Z;
}

/*运算符<<重载,打印向量,返回ostream类便于链式调用*/
ostream & operator<<(ostream &out , Vector &p)
{
    showVector(p);
    return out;
}
