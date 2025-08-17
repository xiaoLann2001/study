#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer(nums1.size(), -1);

        unordered_map<int, int> hash;   // <nums2[i], result>
        // 遍历nums2，用单调栈求nums2中每一个元素的右边第一个大于它的元素

        stack<int> st;  // 递增栈
        st.push(nums2[0]);
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= st.top()) st.push(nums2[i]);
            else {
                while (!st.empty() && nums2[i] > st.top()) {
                    hash[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (hash.count(nums1[i]) > 0) answer[i] = hash[nums1[i]];
        }
        return answer;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> answer =  s.nextGreaterElement(nums1, nums2);

    for (auto n : answer) cout << n << " ";
    cout << endl;

    return 0;
}