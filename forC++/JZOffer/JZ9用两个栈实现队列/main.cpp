#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void push(int node) {
        // stack1负责push，stack2负责pop
        stack1.push(node);
    }

    int pop() {
        // 如果pop栈为空，尝试从push栈取数据，注意要一次取完，保证顺序的一致性
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }

        // 如果pop栈有元素，取出pop栈顶元素
        if (!stack2.empty()) {
            int node = stack2.top();
            stack2.pop();
            return node;
        }

        return -1;  // 表示队列为空
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    

    return 0;
}