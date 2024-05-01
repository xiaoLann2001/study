/**
 * 实现一个通用的数组类，要求如下：
 * 1. 可以对内置数据类型以及自定义数据类型的数据进行存储
 * 2. 将数据存储到堆区
 * 3. 构造函数中可以传入数组的容量
 * 4. 提供拷贝构造函数，并为拷贝构造函数深拷贝数据以及operator=重载
 * 5. 提供尾插法和尾删法对数组中的数据进行增加和删除
 * 6. 可以通过下标的方式访问数组中的元素
 * 7. 可以获取数组中当前元素个数和数组的容量
*/

#pragma once
#include <iostream>
using namespace std;

template <class T>
class myArray
{
public:
    // 构造函数
    myArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pArray = new T[this->m_capacity];
    }

    // 拷贝构造
    myArray(const myArray &arr);

    // operator=重载
    myArray &operator=(const myArray &arr);

    // 尾插法
    void push_back(const T &val);

    // 尾删法
    void pop_back();

    // 通过下标方式访问数组中的元素
    T &operator[](int index);

    // 获取数组中当前元素个数
    int getSize()
    {
        return this->m_size;
    }

    // 获取数组的容量
    int getCapacity()
    {
        return this->m_capacity;
    }

    // 析构函数
    ~myArray()
    {
        if (this->pArray != NULL)
        {
            delete[] this->pArray;
            this->pArray = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
    }

private:
    T *pArray;    // 指向堆区开辟的真实数组
    int m_capacity; // 数组容量
    int m_size;     // 数组大小
};

template <class T>
myArray<T>::myArray(const myArray &arr)
{
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;
    this->pArray = new T[this->m_capacity];
    for (int i = 0; i < this->m_size; i++)
    {
        this->pArray[i] = arr.pArray[i];
    }
}

template <class T>
myArray<T> &myArray<T>::operator=(const myArray &arr)
{
    // 先判断原来堆区是否有数据，如果有先释放
    if (this->pArray != NULL)
    {
        delete[] this->pArray;
        this->pArray = NULL;
        this->m_capacity = 0;
        this->m_size = 0;
    }

    // 深拷贝
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;
    this->pArray = new T[this->m_capacity];
    for (int i = 0; i < this->m_size; i++)
    {
        this->pArray[i] = arr.pArray[i];
    }

    return *this;
}

template <class T>
void myArray<T>::push_back(const T &val)
{
    if (this->m_size == this->m_capacity)
    {
        return;
    }

    this->pArray[this->m_size] = val;
    this->m_size++;
}

template <class T>
void myArray<T>::pop_back()
{
    if (this->m_size == 0)
    {
        return;
    }

    this->m_size--;
}

template <class T>
T &myArray<T>::operator[](int index)
{
    return this->pArray[index];
}
