// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        // 先求总和
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 若总和为奇数，则不可能分割为等和子集，等和子集之和一定为sum / 2
        if (sum % 2) return false;
        // 确定dp数组及其下标含义：dp[i][j]：0~i物品任选，其和是否恰好等于j
        bool dp[nums.size()][sum / 2 + 1];
        // 初始化dp数组
        // 第一列初始化为true，因为空集的和为0
        for (int i = 0; i < nums.size(); i++) dp[i][0] = true;
        // 第一行除了0，只在j = nums[0]时初始化为true
        for (int j = 1; j <= sum / 2; j++) {
            if (nums[0] == j) dp[0][j] = true;
            else dp[0][j] = false;
        }
        // 遍历物品和总和
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= sum / 2; j++) {
                if (nums[i] <= j) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size() - 1][sum / 2];
    }
};

// 滚动数组
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 先求总和
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 若总和为奇数，则不可能分割为等和子集，等和子集之和一定为sum / 2
        if (sum % 2) return false;
        // 确定dp数组及其下标含义：dp[i][j]：0~i物品任选，其和是否恰好等于j
        bool dp[sum / 2 + 1];
        // 初始化dp数组
        // j = 0时为true，其他为false
        for (int j = 0; j <= sum / 2; j++) {
            if (j == 0) dp[j] = true;
            else dp[j] = false;
        }
        // 遍历物品和总和
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum / 2; j >= 0; j--) {    // 倒序遍历
                if (nums[i] <= j) dp[j] = dp[j] || dp[j - nums[i]];
                else dp[j] = dp[j];
            }
        }
        return dp[sum / 2];
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 5, 11, 5};

    bool result = s.canPartition(nums);

    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}