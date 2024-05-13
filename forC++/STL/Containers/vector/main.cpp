#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void Myprint(int val) {
    cout << val << " ";
}

// vector容器存放自定义数据类型
class Person {
public:
    Person(string name, int age) : name(name), age(age) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

private:
    string name;
    int age;
};

// 打印vector容器中的元素
void printVector(vector<int>& v) {
    //第一种遍历方式
    // vector<int>::iterator itBegin = v.begin();
    // vector<int>::iterator itEnd = v.end();
    // while (itBegin != itEnd) {
    //     cout << *itBegin << " ";
    //     ++itBegin;
    // }
    // cout << endl;

    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 第三种遍历方式, 使用STL算法遍历vector并打印元素
    // for_each()函数接受一个迭代器范围和一个函数对象，对范围内的每个元素调用函数对象
    // 该函数对象可以是函数指针、函数对象、lambda表达式
    // for_each(numbers.begin(), numbers.end(), Myprint);   // 函数指针
    // for_each(numbers.begin(), numbers.end(), Myprint);   // 函数对象

    // for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });  // lambda表达式
    // cout << endl;
}

void test1() {
    // vector容器基本概念
    // vector是一个动态数组，可以存放任意类型的数据，也称单端数组
    // vector容器的大小可以动态增长或缩小，不是在原空间上进行扩容，而是重新分配一块更大的空间，将原空间的元素拷贝到新空间
    // vector容器中的元素是连续存储的
    // vector容器中的元素可以通过下标访问（支持随机访问）

    // vector构造函数
    // vector<T> v;  // 创建一个空的vector
    // vector(v.begin(), v.end());  // 将v[begin, end)区间中的元素拷贝给本身，左闭右开
    // vector(n, elem);  // 创建n个elem的vector
    // vector(const vector& v);  // 拷贝构造函数

    // 创建一个空的vector
    vector<int> numbers;    // 默认构造函数

    // 向vector中添加元素
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // 使用迭代器遍历vector并打印元素
    cout << "Vector elements: " << endl;
    printVector(numbers);

    // 访问vector中的元素
    cout << "First element: " << numbers[0] << endl;
    cout << "First element: " << numbers.front() << endl;
    int idx = 1;
    cout << "Pointed pos " << idx << " element: " << numbers.at(idx) << endl;
    cout << "Last element: " << numbers.back() << endl;

    // 修改vector中的元素
    numbers[1] = 50;

    // 删除vector中的元素
    numbers.pop_back();

    // 检查vector是否为空
    if (numbers.empty()) {
        cout << "Vector is empty" << endl;
    } else {
        cout << "Vector size: " << numbers.size() << endl;
    }

    // vector容量
    cout << "Vector capacity: " << numbers.capacity() << endl;

    // vector重新指定大小
    numbers.resize(10, 0);  // 重新指定大小为10，以0填充
    printVector(numbers);

    // vector在指定位置（参数为迭代器）插入元素
    numbers.insert(numbers.begin(), 9);
    printVector(numbers);

    // vector在指定位置（参数为迭代器）擦除元素
    numbers.erase(numbers.begin());
    printVector(numbers);
    // 从[begin, end)删除元素
    numbers.erase(numbers.begin(), numbers.end());
    printVector(numbers);

    // 清空
    numbers.clear();

    // vector容器互换
    vector<int> v1;
    vector<int> v2;
    
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 5);
    }
    
    for (int i = 0; i < 5; i++)
    {
        v2.push_back(i - 5);
    }


    // swap交换容器
    cout << "before swap:" << endl;
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

    v1.swap(v2);

    cout << "after swap:" << endl;
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

    // 巧用swap可以收缩内存空间
    vector<int> v3;
    for (int i = 0; i < 100000; i++)
    {
        v3.push_back(0);
    }
    cout << "v3 's size: " << v3.size() << endl;
    cout << "v3 's capacity: " << v3.capacity() << endl;

    // vector<int>(v3)为匿名对象，capacity为v3.size，交换后v3容量变为capacity，本行执行结束后匿名对象被编译器回收
    vector<int>(v3).swap(v3);
    cout << "v3 's size: " << v3.size() << endl;
    cout << "v3 's capacity: " << v3.capacity() << endl;


    // reserve预留空间，只分配内存，不初始化，不可访问
    vector<int> v4;
    // 记录分配内存次数
    int num;
    int *p;
    for (int i = 0; i < 100000; i++)
    {
        v4.push_back(0);

        if (p != &v4[0])
        {
            p = &v4[0];
            num++;
        }
    }
    cout << "num = " << num << endl;

    vector<int> v5;
    v5.reserve(100000);
    num = 0;
    p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v5.push_back(0);

        if (p != &v5[0])
        {
            p = &v5[0];
            num++;
        }
    }
    cout << "num = " << num << endl;

}

void test2() {
    // vector容器存放自定义数据类型
    vector<Person> persons;

    Person p1("Alice", 20);
    Person p2("Bob", 30);
    Person p3("Cathy", 40);
    Person p4("David", 50);
    Person p5("Eva", 60);

    persons.push_back(p1);
    persons.push_back(p2);
    persons.push_back(p3);
    persons.push_back(p4);
    persons.push_back(p5);

    for (vector<Person>::iterator it = persons.begin(); it != persons.end(); ++it) {
        cout << "Name: " << it->getName() << ", Age: " << it->getAge() << endl;
    }
}

void test3() {
    // vector容器存放自定义数据类型指针
    // vector容器存放的是指针，需要手动释放内存

    vector<Person*> persons;

    Person* p1 = new Person("Alice", 20);
    Person* p2 = new Person("Bob", 30);
    Person* p3 = new Person("Cathy", 40);
    Person* p4 = new Person("David", 50);
    Person* p5 = new Person("Eva", 60);

    persons.push_back(p1);
    persons.push_back(p2);
    persons.push_back(p3);
    persons.push_back(p4);
    persons.push_back(p5);

    for (vector<Person*>::iterator it = persons.begin(); it != persons.end(); ++it) {
        cout << "Name: " << (*it)->getName() << ", Age: " << (*it)->getAge() << endl;
    }

    // 释放内存
    for (vector<Person*>::iterator it = persons.begin(); it != persons.end(); ++it) {
        if (*it != nullptr) {
            delete *it;
            *it = nullptr;
        }
    }

    persons.clear();
}

void test4() {
    // vector容器嵌套vector容器
    // 创建一个二维数组
    
    vector<vector<int>> v;

    // 创建一维数组
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    // 向一维数组中添加元素
    for (int i = 0; i < 5; ++i) {
        v1.push_back(i);
        v2.push_back(i + 1);
        v3.push_back(i + 2);
    }

    // 将一维数组添加到二维数组中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // 遍历二维数组
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it) {
        // 遍历一维数组
        for (vector<int>::iterator vit = it->begin(); vit != it->end(); ++vit) {
            cout << *vit << " ";
        }
        cout << endl;
    }

}

int main() {
    test1();
    // test2();
    // test3();
    // test4();
    
    return 0;
}
