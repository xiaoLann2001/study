// 请你仅使用两个栈实现先入先出队列。
// 队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
// 说明：

// 你只能使用标准的栈操作——也就是只有 push to top, peek/pop from top, size, 
// 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）
// 来模拟一个栈，只要是标准的栈操作即可。


// 思路：用两个栈模拟队列的先进先出，一个 in 栈，一个 out 栈
// 1.当 push 时，直接压入，不需要从out栈里面取，因为out栈元素只有
// 全部弹出后，才从in栈里面取。
// 2.当 pop 时，若 out栈为空，要先将 in栈 所有元素依次弹出并压入
// out 栈，然后 正常 pop 出。
// 总之通过两个栈的 “先进后出，后进先出”，可以模拟 “先进先出”，
// 两个栈同时有元素时不能来回转移，否则整体的顺序会打乱。


#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // 压入新的元素
        in.push(x);
    }
    
    int pop() {
        // 若out栈为空，将in栈全部元素依次弹出并压入到out栈
        if (out.empty()) {
            while (!this->in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        // 若out栈不为空，弹出元素
        int t = out.top();
        out.pop();
        return t;
    }
    
    int peek() {    // 查看队首但不弹出
        // 按理说还应该检查是否为空
        
        // // 先弹出队列
        // int ret = this->pop();

        // // 再压入out栈
        // out.push(ret);

        // return ret;

        return out.top();
    }
    
    bool empty() {
        // 当in栈，out栈都为空时，队列为空
        return in.empty() && out.empty();
    }

private:
    stack<int> in;
    stack<int> out;
};

int main() {
    MyQueue * queue = new MyQueue();

    queue->push(1);
    int param3 = queue->peek();
    int param2 = queue->pop();
    bool param4 = queue->empty();

    cout << param2 << " " << param3 << " " << (param4?1:0) << endl;

    return 0;
}