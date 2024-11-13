// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int m = static_cast<int>(sqrt(static_cast<float>(n)));
        // cout << m << endl;
        vector<int> dp(n + 1, INT32_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }

            // for (auto n : dp) cout << n << " ";
            // cout << endl;
        }

        return dp[n];
    }
};

int main() {
    Solution s;

    int n = 12;

    int result = s.numSquares(n);

    cout << result << endl;

    return 0;
}