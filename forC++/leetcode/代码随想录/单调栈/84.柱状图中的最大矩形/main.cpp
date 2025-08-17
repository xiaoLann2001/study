#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() < 2) return heights[0];
        // 用递减栈从左向右遍历，获得每个位置上向右（包括自身）连续大于等于该位置高度的右边界
        vector<int> right_bound(heights.size(), heights.size() - 1);// 若最后还在栈内，右边界为数组右边界
        stack<int> st_right;
        st_right.push(0);
        for (int i = 1; i < heights.size(); i++) {
            // 情况一：若当前元素大于栈顶元素，构成递减栈，入栈
            if (heights[i] > heights[st_right.top()]) st_right.push(i);
            // 情况二：若当前元素等于栈顶元素，因为要求每个位置的右边界，也入栈
            else if (heights[i] == heights[st_right.top()]) st_right.push(i);
            // 情况三：若当前元素小于栈顶元素，记录栈顶元素所在位置右边界为i - 1，出栈
            else {
                while (!st_right.empty() && heights[i] < heights[st_right.top()]) {
                    right_bound[st_right.top()] = i - 1;
                    st_right.pop();
                }
                st_right.push(i);
            }
        }

        // 用递减栈从右向左遍历，获得每个位置上向左（包括自身）连续大于等于该位置高度的左边界
        vector<int> left_bound(heights.size(), 0);// 若最后还在栈内，左边界为数组左边界
        stack<int> st_left;
        st_left.push(heights.size() - 1);
        for (int i = heights.size() - 2; i >= 0; i--) {
            if (heights[i] > heights[st_left.top()]) st_left.push(i);
            else if (heights[i] == heights[st_left.top()]) st_left.push(i);
            else {
                while (!st_left.empty() && heights[i] < heights[st_left.top()]) {
                    left_bound[st_left.top()] = i + 1;
                    st_left.pop();
                }
                st_left.push(i);
            }
        }

        // cout << "left_bound: "; 
        // for (auto n : left_bound) cout << n << " ";
        // cout << endl;
        // cout << "right_bound: "; 
        // for (auto n : right_bound) cout << n << " ";
        // cout << endl;

        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            int w = right_bound[i] - left_bound[i] + 1;
            int h = heights[i];
            result = max(result, w * h);
        }
        
        return result;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() < 2) return heights[0];
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int result = 0;
        stack<int> st;
        st.push(0);
        // for (int i = 1; i <= heights.size(); i++) {  // size不是原来的size了
        for (int i = 1; i < heights.size(); i++) {
            // 情况一：若当前元素大于栈顶元素，构成递减栈，入栈
            if (heights[i] > heights[st.top()]) st.push(i);
            // 情况二：若当前元素等于栈顶元素，更新栈顶
            else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            }
            // 情况三：若当前元素小于栈顶元素，记录最大矩形，出栈
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int w = i - st.top() - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> heights = {2,1,5,6,2,3};

    int result;
    result = s.largestRectangleArea(heights);

    cout << result << endl;

    return 0;
}