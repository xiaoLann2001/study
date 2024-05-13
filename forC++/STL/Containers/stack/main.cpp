#include <iostream>
#include <stack>

using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

void test1() {
    // 栈的特点
    // 1. 先进后出
    // 2. 只能在栈顶进行插入和删除操作（即只有栈顶能被访问）
    // 3. 栈不提供迭代器
    // 4. 栈不提供遍历操作
    // 5. 栈不提供查找操作
    // 6. 栈不提供排序操作
    // 7. 栈不提供删除操作
    // 8. 栈不提供修改操作
    // 9. 栈提供的操作有：push, pop, top, size, empty

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "栈的大小: " << s.size() << endl;
    // cout << "栈是否为空: " << s.empty() << endl;
    // cout << "栈顶元素: " << s.top() << endl;

    // s.pop();
    // cout << "栈顶元素: " << s.top() << endl;

    while (!s.empty()) {
        cout << "栈顶元素: " << s.top() << endl;

        s.pop();
    }

    cout << "栈的大小: " << s.size() << endl;

}

int main() {
    test1();

    return 0;
}
