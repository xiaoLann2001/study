// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        // 求排列数，先背包后物品
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i]){
                    if (INT32_MAX - dp[j] >= dp[j - nums[i]]) {
                        dp[j] += dp[j - nums[i]];
                    }
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,2,3};
    int target = 4;

    int result = s.combinationSum4(nums, target);

    cout << result << endl;

    return 0;
}