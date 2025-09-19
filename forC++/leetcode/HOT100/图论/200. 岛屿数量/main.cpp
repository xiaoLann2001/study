#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // dfs 或者 bfs 标记已访问，标记一轮计数 +1
        int count = 0;
        vector<vector<bool>> isvisited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // 若当前格子未访问
                if (!isvisited[i][j]) {
                    // 标记已访问
                    isvisited[i][j] = true;

                    // 是陆地，bfs
                    if (grid[i][j] == '1') {
                        bfs(grid, isvisited, i, j);
                        count++;
                    }
                }
            }
        }

        return count;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& isvisited, int row, int col) {
        
        const vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};    // 上下左右

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            pair<int, int> pr = q.front();
            q.pop();

            int row_cur = pr.first;
            int col_cur = pr.second;

            for (auto dr : direction) {
                int row_next = row_cur + dr.first;
                int col_next = col_cur + dr.second;

                // 判断位置是否越界
                if (row_next < 0 || row_next > grid.size() - 1 || col_next < 0 || col_next > grid[0].size() - 1) continue;

                // 是否已访问
                if (!isvisited[row_next][col_next]) {
                    // 标记已访问
                    isvisited[row_next][col_next] = true;
                    // 是否为陆地
                    if (grid[row_next][col_next] == '1') {
                        // 加入队列
                        q.push({row_next, col_next});
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;

    vector<vector<char>> input = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int ret = s.numIslands(input);

    cout << ret << endl;

    return 0;
}