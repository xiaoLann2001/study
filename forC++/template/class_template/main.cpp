#include <iostream>
#include <string>

using namespace std;

// 类模板
template <class NameType, class AgeType = int>
class Person {
public:
    Person(const NameType& name, AgeType age) : m_name(name), m_age(age) {}

    void showPerson() {
        cout << "name: " << m_name << " age: " << m_age << endl;
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
}

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
    // 1.指定传入的类型
    // 2.参数模板化
    // 3.整个类模板化

    Person<string, int> person("John Doe", 25);

    printPerson1(person);
    printPerson2(person);
    printPerson3(person);
    
}

int main() {
    // test1();
    // test2();
    test3();

    return 0;
}
