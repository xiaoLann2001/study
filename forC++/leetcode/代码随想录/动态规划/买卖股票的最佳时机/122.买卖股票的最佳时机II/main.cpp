#include <bits/stdc++.h>

using namespace std;

// 动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (1 == prices.size()) return 0;
        // dp[i][0] : 第 i 天持有股票的最大现金
        // dp[i][1] : 第 i 天不持有股票的最大现金
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] -= prices[0];  // 第 0 天持有，只能买入
        dp[0][1] = 0;   // 第 0 天不持有，现金不变
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][0] + prices[i], dp[i][0] + prices[i]));
        }
        return dp[prices.size() - 1][1];
    }
};

int main() {
    Solution s;

    vector<int> prices = {7,1,5,3,6,4};

    int result = s.maxProfit(prices);

    cout << result << endl;

    return 0;
}