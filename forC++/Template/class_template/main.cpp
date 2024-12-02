#include <iostream>
#include <string>

#include "myArray.hpp"

using namespace std;

// 类模板
template <class NameType, class AgeType = int>
class Person {
public:
    Person() : m_name(""), m_age(0) {}  // 默认构造函数，数组开辟堆区空间时会调用
    Person(const NameType& name, AgeType age) : m_name(name), m_age(age) {}

    void showPerson() {
        cout << "name: " << m_name << " age: " << m_age << endl;
    }

    NameType getName() {
        return m_name;
    }

    AgeType getAge() {
        return m_age;
    }

private:
    NameType m_name;
    AgeType m_age;
};

// 普通类
class Person1 {
public:
    void showPerson1() {
        cout << "Person1" << endl;
    }
};

class Person2 {
public:
    void showPerson2() {
        cout << "Person2" << endl;
    }
};

// 类模板
template<class T>
class MyClass {
public:

    T obj;

    void func1() {
        obj.showPerson1();
    }

    void func2() {
        obj.showPerson2();
    }
};

// 打印Person函数
// 1.指定传入的类型
void printPerson1(Person<string, int>& p) {
    p.showPerson();
}

// 2.参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
    p.showPerson();
    cout << "T1的类型为：" << typeid(T1).name() << endl;
    cout << "T2的类型为：" << typeid(T2).name() << endl;
}

// 3.整个类模板化
template<class T>
void printPerson3(T& p) {
    p.showPerson();
    cout << "T的类型为：" << typeid(T).name() << endl;
}

// 基类模板
template<class T>
class Base1 {
    T m;
};

// 派生类
// class Son : public Base1{ // 错误：必须要知道父类中T的类型

// };

// 派生类模板
// 1.指定父类中T的类型
class Son1 : public Base1<int> {
    
};

//2.如果想灵活指定父类中T的类型，子类也需要变为类模板
template<class T1, class T2>
class Son2 : public Base1<T2> {
public:
    Son2() {
        cout << "T1的类型为：" << typeid(T1).name() << endl;
        cout << "T2的类型为：" << typeid(T2).name() << endl;
    }

    T1 obj;
};

void test1()
{
    // 类模板与函数模板的区别
    // 1.类模板不会自动类型推导，必须显示指定类型
    // 2.类模板在模板参数列表中可以有默认参数

    Person<string, int> person1("John Doe", 25);// 类模板不会自动类型推导，必须显示指定类型
    Person<string> person2("Jane Doe", 30);     // 类模板在模板参数列表中可以有默认参数
    Person<int, int> person3(12345, 30);

    person1.showPerson();
    person2.showPerson();
    person3.showPerson();

}

void test2()
{
    // 类模板中成员函数创建时机
    // 1.普通类中的成员函数一开始就会创建
    // 2.类模板中的成员函数在调用时才会创建

    MyClass<Person1> m;
    m.func1();
    // m.func2();  // error: no member named 'showPerson2' in 'Person1'
}

void test3()
{
    // 类模板对象做函数参数
    // 1.指定传入的类型（最常用）
    // 2.参数模板化
    // 3.整个类模板化

    Person<string, int> person("John Doe", 25);

    printPerson1(person);
    printPerson2(person);
    printPerson3(person);
    
}

void test4()
{
    // 类模板与继承
    // 1.指定父类中T的类型
    // 2.如果不指定，编译器无法给子类分配内存
    // 2.如果想灵活指定父类中T的类型，子类也需要变为类模板

    Son1 son1;
    Son2<int, char> son2;

}

void test5()
{
    // 类模板成员函数类外实现
    // 1.类外实现类模板成员函数时，需要加上模板参数列表
    // 2.类外实现时，不需要加上默认参数

    // 类模板分文件编写
    // 1.类模板分文件编写时，头文件和源文件都要包含类模板的声明和实现
    // 2.类模板分文件编写时，头文件的后缀名为.hpp

    // 类模板和友元
    // 1.全局函数类内实现，直接在类内声明友元即可，声明在全局范围所以是全局函数
    // 2.全局函数类外实现，需要提前让编译器知道全局函数的存在

}

void test6()
{
    // 测试myArray类模板
    myArray<int> arr1(10);
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(5);
    
    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    myArray<int> arr2(arr1);
    arr2.push_back(6);
    arr2.push_back(7);
    arr2.push_back(8);
    arr2.push_back(9);
    arr2.push_back(10);

    for (int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    myArray<int> arr3 = arr2;
    arr3.pop_back();
    arr3.pop_back();
    arr3.pop_back();

    // 测试Person类模板数组
    myArray<Person<string, int>> arr4(10);
    Person<string, int> p1("John Doe", 25);
    Person<string, int> p2("Jane Doe", 30);
    Person<string, int> p3("Jack Doe", 35);
    Person<string, int> p4("Jill Doe", 40);
    Person<string, int> p5("Jim Doe", 45);

    arr4.push_back(p1);
    arr4.push_back(p2);
    arr4.push_back(p3);
    arr4.push_back(p4);
    arr4.push_back(p5);

    for (int i = 0; i < arr4.getSize(); i++)
    {
        cout << "name: " << arr4[i].getName() << " age: " << arr4[i].getAge() << endl;
    }
    cout << endl;

}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();

    return 0;
}
