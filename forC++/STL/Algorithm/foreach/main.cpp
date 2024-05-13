#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myPrint(int val) {
    cout << val << " ";
}

class MyPrint {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test1() {
    // 常用的遍历算法 for_each
    // for_each(iterator begin, iterator end, _func);

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 遍历算法
    for_each(v.begin(), v.end(), myPrint);      // 函数指针
    cout << endl;

    for_each(v.begin(), v.end(), MyPrint());    // 仿函数
    cout << endl;
}

int main() {

    test1();

    return 0;
}