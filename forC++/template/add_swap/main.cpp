#include <iostream>

using std::cout;
using std::endl;

// 创建一个加法运算模板
template<class T>
T func_add(T a, T b)
{
    cout << "T add" << endl;
    return a + b;
}

int func_add(int a, int b)
{
    cout << "int add" << endl;
    return a + b;
}

// 创建一个交换模板
// template<typename T>也可以
template<class T>
T func_swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// 创建一个返回模板
template<class T>
T func_return()
{
    if (std::is_same<T, int>::value)
    {
        return 1;
    }
    else if (std::is_same<T, double>::value)
    {
        return 1.1;
    }
    else
    {
        return 0;
    }
}

// 创建一个排序模板
template<class T>
T* func_sort(T* arr, int len)
{
    // 冒泡排序
    // for (int i = 0; i < len - 1; i++)
    // {
    //     for (int j = 0; j < len - 1 - i; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             func_swap(arr[j], arr[j + 1]);
    //         }
    //     }
    // }

    // 选择排序
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            func_swap(arr[i], arr[min]);
        }
    }

    return arr;
}

// 创建一个打印数组模板
template<class T>
void func_printArray(T* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void test1()
{
    // 函数模板的两种调用方式：
    // 1.自动类型推导：必须推导出一致的数据类型T
    // 2.显式指定类型
    // 函数模板实质：数据类型参数化

    int a = 10;
    int b = 20;
    char c = 'c';

    cout << "sum of " << a << " and " << b << " is " << func_add(a ,b) << endl;

    func_swap<int>(a, b);
    // func_swap(a, c); //错误：无法推导出一致的数据类型T

    cout << "sum of " << a << " and " << b << " is " << func_add(a ,b) << endl;

    cout << "return int: " << func_return<int>() << endl;
    cout << "return double: " << func_return<double>() << endl;
    cout << "return long: " << func_return<long>() << endl;
    // func_return(); //错误：必须给定数据类型T
 
}

void test2()
{
    int arr1[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    double arr2[] = {1.1, 3.3, 5.5, 7.7, 9.9, 2.2, 4.4, 6.6, 8.8, 0.0};
    char arr3[] = {'a', 'c', 'e', 'g', 'i', 'b', 'd', 'f', 'h', 'j'};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    int* res1 = func_sort(arr1, len1);
    double* res2 = func_sort(arr2, len2);
    char* res3 = func_sort(arr3, len3);

    func_printArray(res1, len1);
    func_printArray(res2, len2);
    func_printArray(res3, len3);
}

void test3()
{
    // 普通函数和函数模板的区别
    // 1.普通函数调用时可以发生自动类型转换（隐式类型转换）
    // 2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
    // 3.如果利用显示指定类型的方式，可以发生隐式类型转换
    // 4.函数模板可以发生函数重载
    // 5.普通函数优先于函数模板调用
    // 6.如果函数模板可以产生更好的匹配，优先调用函数模板
    // 7.可以利用“空模板参数列表”来强制调用函数模板

    int a = 10;
    int b = 20;
    char c = 'c';

    cout << "sum of " << a << " and " << b << " is " << func_add(a, b) << endl;     // 优先调用普通函数
    cout << "sum of " << a << " and " << b << " is " << func_add<>(a, b) << endl;     // 优先调用函数模板，使用空模板参数列表
    cout << "sum of " << a << " and " << b << " is " << func_add(a, c) << endl;     // 正确：普通函数发生自动隐式类型转换
    // cout << "sum of " << a << " and " << c << " is " << func_add<>(a, c) << endl;   // 错误：没有指定数据类型T，无法进行隐式类型转换
    cout << "sum of " << a << " and " << c << " is " << func_add<int>(a, c) << endl;// 正确：显式指定数据类型T，可以进行隐式类型转换
    cout << "sum of " << c << " and " << c << " is " << func_add(c, c) << endl;     // 调用函数模板，因为产生更好的匹配

}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}