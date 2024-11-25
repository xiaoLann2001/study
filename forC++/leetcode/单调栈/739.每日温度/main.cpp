#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;  // 单调栈存放已经访问但还未找到右边第一个大于它的元素的元素下标
        int i = 0;
        while (i < temperatures.size()) {
            if (st.empty()) {   // 若栈为空，当前元素一定构成单调栈
                st.push(i);
                i++;
            } else {
                // 若当前元素小于等于栈顶元素，构成单调栈，将当前元素下标压入单调栈
                if (temperatures[i] <= temperatures[st.top()]) {
                    st.push(i);
                    i++;
                } else {    // 若当前元素大于栈顶元素，不构成单调栈，
                            // 说明栈顶找到比它大的元素，记录结果并弹出栈顶
                    result[st.top()] = i - st.top();
                    st.pop();
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    vector<int> answer =  s.dailyTemperatures(temperatures);

    for (auto n : answer) cout << n << " ";
    cout << endl;

    return 0;
}