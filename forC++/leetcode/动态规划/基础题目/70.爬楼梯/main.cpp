#include <iostream>

using namespace std;

class Solution1 {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        // 确定dp数组及其下标含义
        int dp[n + 1];  // 楼梯数i的方法数
        // dp数组初始化，n = 0无意义
        dp[1] = 1;
        dp[2] = 2;
        // 从前往后遍历
        for (int i = 3; i <= n; i++) {
            // 递推公式
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        // 确定dp数组及其下标含义
        int dp[2];  // 前两级楼梯的方法数
        // dp数组初始化，从i=3开始，dp[0]表示dp[i-2]，dp[1]标识dp[i-1]
        dp[0] = 1;
        dp[1] = 2;
        // 从前往后遍历
        int sum = 0;
        for (int i = 3; i <= n; i++) {
            // 递推公式
            sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main() {
    Solution s;

    int n = 4;

    int result = s.climbStairs(n);

    cout << result << endl;

    return 0;
}