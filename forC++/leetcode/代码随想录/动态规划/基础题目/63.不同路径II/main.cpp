#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 确定dp数组及其下标含义
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        // 初始化dp数组，从小到大遍历第一行第一列，
        // 若在遍历时没有障碍物，则dp=1，否则退出循环，其后位置的元素为0，表示无法到达
        for (int i = 0; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        for (int j = 0; j < obstacleGrid[0].size(); j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] == 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main() {
    Solution s;

    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    int result = s.uniquePathsWithObstacles(obstacleGrid);

    cout << result << endl;

    return 0;
}