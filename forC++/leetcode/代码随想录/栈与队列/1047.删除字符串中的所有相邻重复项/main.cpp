// 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的
// 字母，并删除它们。

// 在 s 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result;
        for (int i = s.length() - 1; i >= 0; i--) {
            // 记录暂时没有相邻重复的字符串
            if (st.empty() || s[i] != st.top()) {
                // cout << "push: " << s[i] << endl;
                st.push(s[i]);
            }
            else {  // 去重，注意只删相邻的两个
                // 当前字符等于栈顶元素时，弹出并跳过当前字符
                if (i >= 0 && s[i] == st.top()) {
                    // cout << "pop: " << st.top() << endl;
                    st.pop();
                }
            }   
        } 
        // 弹出结果字符串
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main() {
    Solution s;

    string str = "azxxzy";

    string r = s.removeDuplicates(str);

    cout << r << endl;

    return 0;
}
