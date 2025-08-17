// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<size_t> dp(s.size() + 1, 0);
        dp[0] = 0;

        // 有序背包，容量放外层
        for (int j = 0; j <= s.size(); j++) {
            for (int i = 0; i < wordDict.size(); i++) {
                if (j >= wordDict[i].size()) {
                    // cout << "j: " << j;
                    // cout << "\tword: " << wordDict[i] << "\tword.size(): " << wordDict[i].size();
                    // cout << "\tsubstr: " << s.substr(j - wordDict[i].size(), wordDict[i].size()) << endl;
                    string substr_last = s.substr(j - wordDict[i].size(), wordDict[i].size());
                    if (wordDict[i] == substr_last) {
                        dp[j] = max(dp[j], dp[j - wordDict[i].size()] + wordDict[i].size());
                    }
                }
            }

            for (auto n : dp) cout << n << " ";
            cout << endl;
        }
        if (dp[s.size()] == s.size()) return true;
        return false;
    }
};

int main() {
    Solution s;

    string str = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};

    bool result = s.wordBreak(str, wordDict);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}