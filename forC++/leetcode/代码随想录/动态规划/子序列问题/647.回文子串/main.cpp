#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (1 == s.size()) return 1;
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = s.size() - 1; j >= i; j--) {
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j == i) dp[i][j] = true;
                    else if (j == i + 1) dp[i][j] = true;
                    else if (j > i + 1) dp[i][j] = dp[i + 1][j - 1];
                }
                if (true == dp[i][j]) result++;
            }
        }

        for (auto v : dp) {
            for (auto n : v) {
                cout << n << " ";
            }
            cout << endl;
        }

        return result;
    }
};

int main() {
    Solution sl;

    string s = "abbcacac";

    int result;
    result = sl.countSubstrings(s);

    cout << result << endl;

    return 0;
}