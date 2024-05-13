#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function object class
class MyAdd {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

class MyPrint {
public:
    void operator()(string test) {
        cout << test << endl;
        m_Count++;
    }

    // 记录调用次数
    int m_Count = 0;
};

// 函数对象作为参数
void doPrint(MyPrint &myprint, string test) {
    myprint(test);
}

class GreaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test1() {
    // 函数对象（仿函数）
    // 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
    // 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
    // 3.函数对象可以作为参数传递

    MyAdd myAdd;
    cout << myAdd(10, 20) << endl;
}

void test2() {
    MyPrint myPrint;
    myPrint("Hello World");
    myPrint("Hello World");
    myPrint("Hello World");

    cout << "myPrint调用次数: " << myPrint.m_Count << endl;
}

void test3() {
    // 函数对象作为参数
    MyPrint myPrint;
    doPrint(myPrint, "Hello World");
    
}

void test4() {
    // 返回值为bool类型的函数对象，称为谓词
    // 一元谓词，只有一个参数
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 10);
    }
    
    // 查找容器中是否有没有大于5的数字
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到: " << *it << endl;
    }

    // 普通排序，默认从小到大
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 二元谓词，有两个参数
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

}

void test5() {
    // 内建函数对象：STL内建了一些函数对象
    // 分类：
    // 算数仿函数
    // 关系仿函数
    // 逻辑仿函数
    // 用法：
    // 包含头文件 #include <functional>

    // 算数仿函数
    // template<class T> T plus<T> // 加法仿函数
    // template<class T> T minus<T> // 减法仿函数
    // template<class T> T multiplies<T> // 乘法仿函数
    // template<class T> T divides<T> // 除法仿函数
    // template<class T> T modulus<T> // 取模仿函数
    // template<class T> T negate<T> // 取反仿函数

    // 一元算数仿函数
    negate<int> n;
    cout << n(50) << endl;

    // 二元算数仿函数
    plus<int> p;
    cout << p(10, 20) << endl;


    // 关系仿函数
    // template<class T> bool equal_to<T> // 等于
    // template<class T> bool not_equal_to<T> // 不等于
    // template<class T> bool greater<T> // 大于
    // template<class T> bool greater_equal<T> // 大于等于
    // template<class T> bool less<T> // 小于
    // template<class T> bool less_equal<T> // 小于等于

    greater<int> g;
    cout << g(10, 20) << endl;

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 10);
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());   // greater<int>() 临时对象
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    // 逻辑仿函数
    // template<class T> bool logical_and<T> // 逻辑与
    // template<class T> bool logical_or<T> // 逻辑或
    // template<class T> bool logical_not<T> // 逻辑非

    vector<bool> v2;
    v2.push_back(true);
    v2.push_back(false);
    v2.push_back(true);
    v2.push_back(false);

    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 利用逻辑非，将容器v2搬运到v3中
    vector<bool> v3;

    // transform(v2.begin(), v2.end(), v3.begin(), logical_not<bool>());    // 第三个参数传迭代器
    transform(v2.begin(), v2.end(), back_inserter(v3), logical_not<bool>());// back_inserter插入迭代器
    for (vector<bool>::iterator it = v3.begin(); it != v3.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;



}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    test5();


    return 0;
}
