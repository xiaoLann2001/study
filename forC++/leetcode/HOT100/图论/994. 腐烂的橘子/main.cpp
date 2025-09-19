#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        // 至少需要的时间 = 所有连成片的橘子腐烂的最大时间
        // 一片区域有多个腐烂橘子怎么办：bfs一开始放入多个橘子，同时遍历
        // 有没有独立的未腐烂的橘子：返回-1
        // 没有腐烂橘子怎么办：返回0
        const vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};    // 上下左右
        
        int time_least = -1;    // bfs层数包括初始层，要减去初始的时间 
        queue<pair<int, int>> q;

        bool haveOrange = false;

        // 加入所有一开始就腐烂了的橘子
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    if (!haveOrange) haveOrange = true;
                    if (grid[i][j] == 2) {
                        q.push({i, j});
                    }
                }
            }
        }

        // 没有橘子
        if (!haveOrange) return 0;

        // bfs
        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> pr = q.front();
                q.pop();

                int row_cur = pr.first;
                int col_cur = pr.second;

                for (auto dr : direction) {
                    int row_next = row_cur + dr.first;
                    int col_next = col_cur + dr.second;

                    // 判断位置是否越界
                    if (row_next < 0 || row_next > grid.size() - 1 || col_next < 0 || col_next > grid[0].size() - 1) continue;

                    // 是否是橘子
                    if (grid[row_next][col_next] > 0) {
                        // 是否未腐烂
                        if (grid[row_next][col_next] == 1) {
                            // 标记腐烂
                            grid[row_next][col_next] = 2;
                            // 加入队列
                            q.push({row_next, col_next});
                        }
                    }
                }
            }

            time_least++;
        }

        // 检查有没有未腐烂的橘子
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time_least;
    }
};

int main() {
    Solution s;

    vector<vector<int>> input = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int ret = s.orangesRotting(input);

    cout << ret << endl;

    return 0;
}