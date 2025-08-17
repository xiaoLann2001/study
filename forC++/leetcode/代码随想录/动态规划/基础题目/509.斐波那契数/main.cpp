#include <iostream>

using namespace std;

class Solution2 {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};

class Solution2 {
public:
    int fib(int n) {
        if (n < 2) return n;
        // 确定dp数组
        int dp[n + 1];
        // 初始化dp数组
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            // 递推公式
            dp[i] = dp[i - 1] + dp[i - 2];
            // 从前往后遍历
        }
        return dp[n];
    }
};

class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main() {
    Solution s;

    int n = 4;

    int result = s.fib(n);

    cout << result << endl;

    return 0;
}