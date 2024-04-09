#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person
{    
private:
    string m_name;
    int m_age;
public:
    Person(string name, int age);
    void showPerson(void);
    ~Person();
};

Person::Person(string name, int age)
{
    this->m_name = name;
    this->m_age = age;
}

void Person::showPerson(void)
{
    cout << this->m_name << "\t" << this->m_age << endl;
}

Person::~Person()
{
}

void myPrint(Person& p)
{
    p.showPerson();
}

int main()
{
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);

    // vector<int>::iterator itBegin = v.begin();
    // vector<int>::iterator itEnd = v.end();
    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // for (vector<int>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++)
    // {
    //     cout << *itBegin << endl;
    // }


    Person p1("张三", 50);
    Person p2("李四", 60);

    vector<Person> v_person;
    v_person.push_back(p1);
    v_person.push_back(p2);

    //使用algorithm
    for_each(v_person.begin(), v_person.end(), myPrint);

    return 0;
}