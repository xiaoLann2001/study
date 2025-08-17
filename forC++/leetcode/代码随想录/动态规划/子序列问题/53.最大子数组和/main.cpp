#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (result < dp[i]) result = dp[i];
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int result;
    result = s.maxSubArray(nums);

    cout << result << endl;

    return 0;
}