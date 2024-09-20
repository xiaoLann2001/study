// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的
// 全部四种操作（push、top、pop 和 empty）。

// 实现 MyStack 类：

// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

// 注意：

// 你只能使用队列的标准操作——也就是 push to back、peek/pop from front、
// size 和 is empty 这些操作。
// 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者
// deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    MyStack()
    {

    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        if (0 == q.size()) {
            cout << "stack empty!" << endl;
        }

        // 将q中除最后一个元素的其他元素存入q_copy
        while (q.size() > 1) {
            q_copy.push(q.front());
            q.pop();
        }

        // 将q中最后一个元素弹出
        int r = q.front();
        q.pop();

        // 将q_copy中所有元素存回q
        while (!q_copy.empty()) {
            q.push(q_copy.front());
            q_copy.pop();
        }

        return r;
    }

    int top()
    {
        int r = this->pop();
        this->push(r);
        return r;
    }

    bool empty()
    {
        return q.empty();
    }
private:
    queue<int> q;
    queue<int> q_copy;
};

int main()
{

    MyStack *obj = new MyStack();
    obj->push(2);
    int param_3 = obj->top();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();

    cout << param_2 << " "
         << param_3 << " "
         << param_4 << " "
         << endl;

    return 0;
}