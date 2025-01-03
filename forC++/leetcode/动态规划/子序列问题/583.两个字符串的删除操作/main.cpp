#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // for (auto v : dp) {
        //     for (auto n : v) {
        //         cout << n << " ";
        //     }
        //     cout << endl;
        // }

        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};

int main() {
    Solution s;

    string text1 = "leetcode";
    string text2 = "etco";

    int result;
    result = s.minDistance(text1, text2);

    cout << result << endl;

    return 0;
}