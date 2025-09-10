#include <bits/stdc++.h>

using namespace std;

// 贪心
class Solution1 {
public:
    int maxSumOfSubArray(vector<int> array) {
        if (array.empty()) return 0;    // 没有子数组
        int sum = array[0];             // 记录以array[i]结尾的最大子数组的和
        int maxSum = max(0, sum);       // 记录最大子数组的和
        for (int i = 1; i < array.size(); i++) {
            if (sum <= 0) {             // 若以array[i]结尾的最大子数组的和小于等于0，则舍弃前面的数，从下一个数重新开始统计，否则最大子数组和只会更小
                sum = 0;
            }
            sum += array[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

// 动态规划
class Solution {
public:
    int maxSumOfSubArray(vector<int> array) {
        if (array.empty()) return 0;    // 没有子数组
        vector<int> dp(array.size(), 0);    // dp[i]：以array[i]结尾的子数组的最大和
        dp[0] = max(0, array[0]);
        int maxSum = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(array[i], dp[i - 1] + array[i]);    // dp[i]来自两种情况：舍弃前面的和，保留前面的和；取最大
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};    // maxSum = 18

    int ret = s.maxSumOfSubArray(nums);
    
    cout << ret << endl;

    return 0;
}