// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int floor(int n, int m) {
        vector<int> dp(n + 1, 0);   // dp[j]:容量为j的背包的放置物品总价值为j的排列数，物品价值等于物品重量
        dp[0] = 1;  // 初始化dp数组
        for (int j = 0; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                if (j >= i) {
                    if (INT32_MAX - dp[j] >= dp[j - i]) {
                        dp[j] += dp[j - i];
                    }
                }
            }

            // // 打印 dp 数组
            // for (auto n : dp) cout << n << " ";
            // cout << endl;
        }
        return dp[n];
    }
}; 

int main() {
    Solution s;

    int n, m;

    cin >> n >> m;

    int result = s.floor(n, m);

    cout << result << endl;

    return 0;
}