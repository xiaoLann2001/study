#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        if (pushV.size() != popV.size())
            return false;
        // 辅助栈模拟压入、弹出，如果最后所有元素都弹出了，说明可行
        stack<int> st;
        int indexPush = 0;   // 记录当前待压入的元素索引
        int indexPop = 0;   // 记录当前待弹出元素索引
        while (indexPush < pushV.size() && indexPop < popV.size()) {
            // 若栈顶元素不等于待弹出元素，压入待压入元素，直到栈顶等于待弹出元素
            while (indexPush < pushV.size() && (st.empty() || st.top() != popV[indexPop])) {
                st.push(pushV[indexPush]);
                indexPush++;
            }
            // 若栈顶元素等于待弹出元素
            while (indexPop < popV.size() && (!st.empty() && st.top() == popV[indexPop])) {
                st.pop();
                indexPop++;
            }
        }
        if (indexPop == popV.size())
            return true;
        return false;
    }
};

int main() {
    Solution s;

    // vector<int> pushV = {1,2,3,4,5};
    // vector<int> popV = {5,4,3,2,1};
    // vector<int> pushV = {1};
    // vector<int> popV = {2};
    vector<int> pushV = {2,1,0};
    vector<int> popV = {1,2,0};

    bool ret = s.IsPopOrder(pushV, popV);

    cout << ret << endl;

    return 0;
}