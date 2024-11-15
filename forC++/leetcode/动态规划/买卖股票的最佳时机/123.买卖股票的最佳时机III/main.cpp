#include <bits/stdc++.h>

using namespace std;

// 动态规划
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if (1 == prices.size()) return 0;
        // dp[i][0] : 第 i 天持有股票的最大现金
        // dp[i][1] : 第 i 天不持有股票的最大现金
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] -= prices[0];  // 第 0 天持有，只能买入
        dp[0][1] = 0;           // 第 0 天不持有，现金不变
        
        for (int i = 0; i < 2; i++) {
            for (int i = 1; i < prices.size(); i++) {
                // 只能取dp[i][1]，因为dp[i - 1][1]已经被这轮覆盖
                // 而dp[i][1]仍保留第i天上一轮不持有股票的最大现金，可在这一天再次买入

                // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
                dp[i][0] = max(dp[i - 1][0], dp[i][1] - prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            }

            // // 打印dp数组
            // for (int i = 0; i < prices.size(); i++) {
            //     cout << dp[i][0] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < prices.size(); i++) {
            //     cout << dp[i][1] << " ";
            // }
            // cout << endl;
        }

        return dp[prices.size() - 1][1];
    }
};

// 动态规划，流水线多个循环
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (1 == prices.size()) return 0;
        // dp[i][0] : 第 i 天第一次持有股票的最大现金
        // dp[i][1] : 第 i 天第一次不持有股票的最大现金
        // dp[i][2] : 第 i 天第二次持有股票的最大现金
        // dp[i][3] : 第 i 天第二次不持有股票的最大现金
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] -= prices[0];  // 第 0 天第一次持有，只能买入
        dp[0][2] -= prices[0];  // 第 0 天第二次持有，只能买入
        
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], 0 - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            // 也可以取dp[i - 1][1]，因为dp[i - 1][1]单独保留了
            // dp[i - 1][1]保留了第i-1天上一轮不持有股票的最大现金，可在后一天也就是当天买入
            // dp[i][1]保留了第i天上一轮不持有股票的最大现金，可在这一天再次买入

            // dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }

        for (int i = 0; i < prices.size(); i++) {
            cout << dp[i][0] << " ";
        }
        cout << endl;
        for (int i = 0; i < prices.size(); i++) {
            cout << dp[i][1] << " ";
        }
        cout << endl;
        for (int i = 0; i < prices.size(); i++) {
            cout << dp[i][2] << " ";
        }
        cout << endl;
        for (int i = 0; i < prices.size(); i++) {
            cout << dp[i][3] << " ";
        }
        cout << endl;

        return dp[prices.size() - 1][3];
    }
};

int main() {
    Solution1 s;

    vector<int> prices = {3,3,5,0,0,3,1,4};

    int result = s.maxProfit(prices);

    cout << result << endl;

    return 0;
}