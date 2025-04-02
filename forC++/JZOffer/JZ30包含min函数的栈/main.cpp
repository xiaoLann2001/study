#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void push(int value) {
        m_st.push(value);
        if (m_minSt.empty()) {
            m_minSt.push(value);
        } else {
            m_minSt.push(std::min(value, m_minSt.top()));    // 更新最小值
        }
    }
    void pop() {
        if (m_st.empty() || m_minSt.empty()) {
            return;
        }
        m_st.pop();
        m_minSt.pop();
    }
    int top() {
        if (m_st.empty()) {
            return -1;
        }
        return m_st.top();
    }
    int min() {
        if (m_minSt.empty()) {
            return -1;
        }
        return m_minSt.top();
    }
private:
    stack<int> m_st;
    stack<int> m_minSt;
};

int main() {
    Solution s;

    s.push(-1);
    cout << "push: " << -1 << endl;

    s.push(2);
    cout << "push: " << 2 << endl;

    cout << "min:  " << s.min() << endl;

    cout << "top:  " << s.top() << endl;

    s.pop();
    cout << "pop" << endl;

    s.push(-1);
    cout << "push: " << -1 << endl;

    cout << "top:  " << s.top() << endl;

    cout << "min:  " << s.min() << endl;

    return 0;
}