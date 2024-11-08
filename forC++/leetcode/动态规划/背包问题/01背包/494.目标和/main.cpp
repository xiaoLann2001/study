// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || (sum - abs(target)) % 2 != 0) return 0;
        int capacity = (sum - abs(target)) / 2;
        vector<int> dp(capacity + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = capacity; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[capacity];
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    int result = s.findTargetSumWays(nums, target);

    cout << result << endl;

    return 0;
}