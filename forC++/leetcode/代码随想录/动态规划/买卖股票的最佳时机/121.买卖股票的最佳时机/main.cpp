#include <bits/stdc++.h>

using namespace std;

// 贪心，参考最大子序和
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if (1 == prices.size()) return 0;
        int accumlate_profit = 0, result = 0;
        for (int i = 1; i < prices.size(); i++) {
            // cout << "i :" << i << "\tgap: " << prices[i] - prices[i - 1] << endl;
            accumlate_profit += (prices[i] - prices[i - 1]);
            if (accumlate_profit < 0) accumlate_profit = 0;
            else result = max(result, accumlate_profit);
        }
        return result;
    }
};

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
            // 第 i 天持有股票的最大现金，取保持持有与买入的最大值，
            // 买入后的现金等于 0 - prices[i]，因为题目要求只买一次，初始值一定为 0
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // 第 i 天不持有股票的最大现金，取保持不持有与卖出的最大值，
            // 卖出后的现金等于 当天股票价格 加上 前一天持有的最大现金
            // （dp[i][0]在这里其实就是负的买入成本，从一开始就买了，后面只是在找更便宜的买入价格）
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
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