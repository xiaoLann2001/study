#include <iostream>
#include <list> 

using namespace std;

class Person {
public:
    Person(string name, int age, int height) : m_name(name), m_age(age), m_height(height) {}
    
    string m_name;
    int m_age;
    int m_height;
};

void printList(const list<Person>& l) {
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++) {
        cout << "Name: " << it->m_name << " Age: " << it->m_age << " Height: " << it->m_height << endl;
    }
    cout << endl;
}

// 排序规则：按年龄升序，年龄相同按身高降序
bool myCompare(const Person& p1, const Person& p2) {
    if (p1.m_age == p2.m_age) {
        return p1.m_height > p2.m_height;
    }
    return p1.m_age < p2.m_age;
}

int main() {

    list<Person> l;
    Person p1("aaa", 15, 171);
    Person p2("bbb", 25, 180);
    Person p3("ccc", 31, 160);
    Person p4("ddd", 25, 100);
    Person p5("eee", 25, 182);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);

    printList(l);

    l.sort(myCompare);

    printList(l);
    
    return 0;
}
