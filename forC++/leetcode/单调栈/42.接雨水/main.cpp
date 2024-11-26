#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int trap(vector<int>& height) {
        vector<int> right_max(height.size(), 0);
        vector<int> left_max(height.size(), 0);
        int result = 0;
        // 找到每个元素右边最大的元素
        int temp_max = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            right_max[i] = temp_max;
            if (height[i] > temp_max) temp_max = height[i];
        }
        // 找到每个元素左边最大的元素
        temp_max = 0;
        for (int i = 0; i < height.size(); i++) {
            left_max[i] = temp_max;
            if (height[i] > temp_max) temp_max = height[i];
        }
        // 求雨水
        for (int i = 0; i < height.size(); i++) {
            result += max(0, min(left_max[i], right_max[i]) - height[i]);
        }
        return result;
    }
};

// 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int result = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            // 情况一：当前元素小于栈顶元素时，压栈
            if (height[i] < height[st.top()]) st.push(i);
            // 情况二：当前元素等于栈顶元素时，更新栈顶
            else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            }
            // 情况三：当前元素大于栈顶元素时，出现凹槽，计算接水量
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top(); // 凹槽底部位置
                    st.pop();
                    if (st.empty()) break; // 若凹槽没有左壁，则接不了雨水
                    int left = st.top();    // 凹槽左壁位置
                    int right = i;          // 凹槽右壁位置
                    int w = i - st.top() - 1;   // 水柱宽度
                    int h = min(height[left], height[right]) - height[mid]; // 水柱高度
                    result += w * h;
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = s.trap(height);

    cout << result << endl;

    return 0;
}