// 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 
// 表示的算术表达式。

// 请你计算该表达式。返回一个表示表达式值的整数。

// 注意：

// 有效的算符为 '+'、'-'、'*' 和 '/' 。
// 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
// 两个整数之间的除法总是 向零截断 。
// 表达式中不含除零运算。
// 输入是一个根据逆波兰表示法表示的算术表达式。
// 答案及所有中间计算结果可以用 32 位 整数表示。

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for (string str : tokens) {
            // C++中，字符串可以直接比较
            if (str[0] >= '0' && str[0] <= '9' ||
                (str.length() > 1 && str[0] == '-')) {
                // cout << "push: " << stoi(str) << endl;
                result.push(stoi(str));
            } else {
                int b = result.top();
                result.pop();
                int a = result.top();
                result.pop();
                int temp = 0;
                if (str[0] == '+') temp = a + b;
                else if (str[0] == '-') temp = a - b;
                else if (str[0] == '*') temp = a * b;
                else if (str[0] == '/') temp = a / b;
                // cout << "temp: " << temp << endl;
                result.push(temp);
            }
        }
        return result.top();
    }
};

class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for (string str : tokens) {
            // C++中，字符串可以直接比较
            if (str == "+" || str == "-" || 
                str == "*" || str == "/") {
                int b = result.top();
                result.pop();
                int a = result.top();
                result.pop();
                int temp = 0;
                if (str[0] == '+') temp = a + b;
                else if (str[0] == '-') temp = a - b;
                else if (str[0] == '*') temp = a * b;
                else if (str[0] == '/') temp = a / b;
                // cout << "temp: " << temp << endl;
                result.push(temp);
            } else {
                result.push(stoi(str));
            }
        }
        return result.top();
    }
};

int main() {
    Solution s;

    vector<string> tokens = {"10","6","9","3","+","-11","*","/",
                            "*","17","+","5","+"};

    int r = s.evalRPN(tokens);

    cout << r << endl;

    return 0;
}
