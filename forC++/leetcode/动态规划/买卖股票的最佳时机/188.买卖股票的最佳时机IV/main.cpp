#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (1 == prices.size()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            dp[0][2 * i - 1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= k; j++) {
                dp[i][2 * j - 1] = max(dp[i - 1][2 * j - 1], dp[i - 1][2 * j - 2] - prices[i]);
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]);
            }
        }
        // for (auto v : dp) {
        //     for (auto n : v) cout << n << " ";
        //     cout << endl;
        // }
        return dp[prices.size() - 1][2 * k];
    }
};

int main() {
    Solution s;

    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};

    int result = s.maxProfit(k, prices);

    cout << result << endl;

    return 0;
}