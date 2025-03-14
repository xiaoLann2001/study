#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    if (dp[i - 1][j - 1] <= INT32_MAX - dp[i - 1][j]) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main() {
    Solution sl;

    string s = "rabbbit";
    string t = "rabbit";

    int result;
    result = sl.numDistinct(s, t);

    cout << result << endl;

    return 0;
}