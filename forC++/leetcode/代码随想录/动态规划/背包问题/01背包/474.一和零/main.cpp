// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 统计每个字符串的零和一个数
        vector<int> zero(strs.size(), 0);
        vector<int> one(strs.size(), 0);
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') zero[i]++;
                else if (strs[i][j] == '1') one[i]++;
            }
        }
        // 定义dp数组并初始化
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            // 更新dp数组，按容量倒序遍历
            for (int j = m; j >= zero[i]; j--) {
                for (int k = n; k >= one[i]; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zero[i]][k - one[i]]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;

    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    int result = s.findMaxForm(strs, m, n);

    cout << result << endl;

    return 0;
}