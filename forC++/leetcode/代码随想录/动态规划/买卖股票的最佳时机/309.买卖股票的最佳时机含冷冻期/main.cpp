#include <bits/stdc++.h>

using namespace std;

// 动态规划，流水线多个循环
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][1] = -prices[0];
        dp[1][1] = max(-prices[0], -prices[1]);
        dp[1][2] = prices[1] - prices[0];
        for (int i = 2; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            // 保持卖出状态已经包含前一天卖出的结果，不需要从前两天卖出状态买入
            // dp[i][1] = max(dp[i - 1][0] - prices[i],
            //            max(dp[i - 1][1], 
            //            max(dp[i - 2][2] - prices[i], 
            //                dp[i - 1][3] - prices[i])));
            dp[i][1] = max(dp[i - 1][0] - prices[i],
                       max(dp[i - 1][1], dp[i - 1][3] - prices[i]));
            dp[i][2] = dp[i - 1][1] + prices[i];
            dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);
        }
        for (auto v : dp) {
            for (auto n : v) cout << n << " ";
            cout << endl;
        }
        return max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]);
    }
};

int main() {
    Solution s;

    vector<int> prices = {1,2,3,0,2};

    int result = s.maxProfit(prices);

    cout << result << endl;

    return 0;
}