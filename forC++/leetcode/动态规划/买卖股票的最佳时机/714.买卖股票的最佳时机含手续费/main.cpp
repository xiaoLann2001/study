#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() < 2) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][2] - prices[i]));
            dp[i][1] = dp[i - 1][0] + prices[i] - fee;
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};

int main() {
    Solution s;

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = s.maxProfit(prices, 2);

    cout << result << endl;

    return 0;
}