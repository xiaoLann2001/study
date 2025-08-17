// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，
// 判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。

// 示例 1：

// 输入：s = "()"

// 输出：true

// 示例 2：

// 输入：s = "()[]{}"

// 输出：true

// 示例 3：

// 输入：s = "(]"

// 输出：false

// 示例 4：

// 输入：s = "([])"

// 输出：true


#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    stack<char> st;

    bool isValid(string s) {
        for (char c : s) {
            // 若是一对括号，栈中一定是存左括号，c为右括号
            if (!st.empty() && this->isPair(st.top(), c)) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }

    // 注意isPair()是要区分左右的
    bool isPair(char left, char right) {
        if ((left == '(' && right == ')') || 
            (left == '[' && right == ']') ||
            (left == '{' && right == '}')) return true;
        return false;
    }
};

class Solution1 {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，
            // 说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。
            // 所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号
        // 没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};

int main() {
    Solution s;

    string str = "([)";

    if (s.isValid(str)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
