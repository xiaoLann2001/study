#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];  // 无操作
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }

        for (auto v : dp) {
            for (auto n : v) cout << n << " ";
            cout << endl;
        }

        return dp[word1.size()][word2.size()];
    }
};

int main() {
    Solution s;

    string word1 = "sea";
    string word2 = "eat";

    int result;
    result = s.minDistance(word1, word2);

    cout << result << endl;

    return 0;
}