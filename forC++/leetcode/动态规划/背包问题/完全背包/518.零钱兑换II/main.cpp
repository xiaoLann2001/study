// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        vector<int> dp(amount + 1, 0);  // 背包容量为 i 时，有 dp[i] 种组合能让背包装满
        dp[0] = 1;
            for (int j = 0; j <= amount; j++) {
        for (int i = 0; i < coins.size(); i++) {
                if (j >= coins[i]) {
                    if (INT32_MAX - dp[j] >= dp[j - coins[i]]) {
                        dp[j] += dp[j - coins[i]];
                    }
                }
            }

            for (auto n : dp) cout << n << ' ';
            cout << endl;
        }
        return dp[amount];
    }
};

int main() {
    Solution s;

    vector<int> coins = {1,2,5};
    int amount = 5;

    int result = s.change(amount, coins);

    cout << result << endl;

    return 0;
}