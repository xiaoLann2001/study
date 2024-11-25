#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int result = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] != s[j]) dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                else {
                    if (i == j) dp[i][j] = 1;
                    else if (i + 1 == j) dp[i][j] = 2;
                    else if (i + 1 < j) dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }

        // for (auto v : dp) {
        //     for (auto n : v) cout << n << " ";
        //     cout << endl;
        // }

        return result;
    }
};

int main() {
    Solution sl;

    string s = "bbbab";

    int result;
    result = sl.longestPalindromeSubseq(s);

    cout << result << endl;

    return 0;
}