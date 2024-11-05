#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 确定dp数组及其下标含义
        // dp[i][j]表示到达(i,j)的路径数
        vector<vector<int>> dp(m, vector<int>(n, 1));
        // 第一行第一列初始化为1，其他的会在运行时被覆盖
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;

    int m = 3;
    int n = 7;

    int result = s.uniquePaths(m, n);

    cout << result << endl;

    return 0;
}