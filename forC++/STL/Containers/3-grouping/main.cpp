#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Employee {
public:
    Employee(string name, int salary = 0) {
        this->name = name;
        this->salary = salary;
    }
    
    string name;
    int salary;
};

void printEmployees(const vector<Employee> employees) {
    for (vector<Employee>::const_iterator it = employees.begin(); it != employees.end(); it++) {
        cout << it->name << " " << it->salary << endl;
    }
    cout << endl;
}

void printEmployeesAndSection(const multimap<int, Employee> m) {
    for (multimap<int, Employee>::const_iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second.name << " " << it->second.salary << endl;
    }
    cout << endl;
}

int main() {
    vector<Employee> employees;

    for (int i = 0; i < 10; i++)
    {
        // 随机分配工资和部门，名字为ABCD...
        employees.push_back(Employee(string(1, 'A' + i), rand() % 1000 + 1000));
    }

    printEmployees(employees);

    multimap<int, Employee> m;

    for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); it++) {
        int section = rand() % 3 + 1;
        m.insert(make_pair(section, *it));
    }

    printEmployeesAndSection(m);

    cout << "Section 1:" << "total :" << m.count(1) << endl;
    while (m.find(1) != m.end()) {
        cout << m.find(1)->second.name << " " << m.find(1)->second.salary << endl;
        m.erase(m.find(1));
    }

    cout << "Section 2:" << "total :" << m.count(2) << endl;
    while (m.find(2) != m.end()) {
        cout << m.find(2)->second.name << " " << m.find(2)->second.salary << endl;
        m.erase(m.find(2));
    }

    cout << "Section 3:" << "total :" << m.count(3) << endl;
    while (m.find(3) != m.end()) {
        cout << m.find(3)->second.name << " " << m.find(3)->second.salary << endl;
        m.erase(m.find(3));
    }


    return 0;
}
