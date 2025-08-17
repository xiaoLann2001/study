#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> st;  // 存元素下标
        st.push(0);
        // 循环遍历两遍
        for (int i = 1, j = 0; i < nums.size() && j < 2; j += (i + 1) / nums.size(),  i = (i + 1) % nums.size()) {
            if (nums[i] <= nums[st.top()]) st.push(i);
            else {
                while (!st.empty() && nums[i] > nums[st.top()]) {
                    result[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,2,3,4,3};

    vector<int> answer =  s.nextGreaterElements(nums);

    for (auto n : answer) cout << n << " ";
    cout << endl;

    return 0;
}