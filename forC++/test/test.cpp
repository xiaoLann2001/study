#include <iostream>

// 创建一个加法运算模板
template<class T>
T func_add(T a, T b)
{
    return a + b;
}

// 创建一个交换模板
template<class T>
T func_swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    using std::cout;
    using std::endl;

    int a = 10;
    int b = 20;

    cout << "sum of " << a << " and " << b << " is " << func_add(a ,b) << endl;

    func_swap(a, b);

    cout << "sum of " << a << " and " << b << " is " << func_add(a ,b) << endl;

    return 0;
}