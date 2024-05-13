#include <iostream>
#include <queue>

using namespace std;

void test1() {
    // queue的特点
    // 1. 先进先出
    // 2. 只能在队列的尾部插入元素
    // 3. 只能在队列的头部删除元素（即只有队首队尾能被访问）
    // 4. 队列不提供迭代器
    // 5. 队列不提供遍历操作
    // 6. 队列不提供查找操作
    // 7. 队列不提供排序操作
    // 8. 队列不提供删除操作
    // 9. 队列不提供修改操作
    // 10. 队列提供的操作有：push, pop, front, back, size, empty

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "队列的大小: " << q.size() << endl;
    while (!q.empty()) {
        cout << "队首元素: " << q.front() << endl;
        cout << "队尾元素: " << q.back() << endl;

        q.pop();
    }
}

int main() {
    test1();

    return 0;
}
