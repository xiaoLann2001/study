#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test1() {
    // 常用遍历算法transform
    // 将指定操作应用于范围内的每个元素，并将结果存储在另一个范围中
    // transform(iterator begin1, iterator end1, iterator begin2, _func);

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });  // lambda表达式
    cout << endl;

    vector<int> vTarget;
    vTarget.resize(v.size());

    transform(v.begin(), v.end(), vTarget.begin(), [](int val) { return val + 100; });
    for_each(vTarget.begin(), vTarget.end(), [](int val) { cout << val << " "; });
    cout << endl;
}

int main() {

    test1();

    return 0;
}