#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp1(nums.size(), 0);    // 选第一户
        vector<int> dp2(nums.size(), 0);    // 不选第一户
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            if (i < nums.size() - 1) {
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp1[nums.size() - 2], dp2[nums.size() - 1]);
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,2,3,1};

    int result = s.rob(nums);

    cout << result << endl;

    return 0;
}