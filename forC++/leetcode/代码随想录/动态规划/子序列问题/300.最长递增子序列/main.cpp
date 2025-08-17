#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i< nums.size(); i++) {
            for (int j = 1; j <= i; j++) {
                if (nums[i] > nums[i - j]) {
                    dp[i] = max(dp[i], dp[i - j] + 1);
                }
            }
        }

        // for (auto n : dp) cout << n << " ";
        // cout << endl;

        int result = 0;
        for (auto n : dp) {
            if (n > result) result = n;
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,3,6,7,9,4,10,5,6};

    int result = s.lengthOfLIS(nums);

    cout << result << endl;

    return 0;
}