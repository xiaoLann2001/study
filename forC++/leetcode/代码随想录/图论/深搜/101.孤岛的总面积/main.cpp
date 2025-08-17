#include <bits/stdc++.h>

using namespace std;

// 四个搜索方向
const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 深搜，返回岛屿面积，以引用形式返回岛屿面积是否有效
int dfs(const vector<vector<int>> &map, vector<vector<bool>> &visited, int x_cur, int y_cur, int &valid) {
    // 1.终止条件：遇到水域或者已访问的格子
    if (map[x_cur][y_cur] == 0 || visited[x_cur][y_cur] == true) return 0;
    // 2.处理当前格子
    visited[x_cur][y_cur] = true;   // 标记已访问
    int squre = 1;                  // 当前访问格子面积为 1，会在递归时累加
    if (x_cur == 0 || y_cur == 0 || // 触碰边界，标记无效
        x_cur == map.size() - 1 || y_cur == map[0].size() - 1) valid = 0;
    // 3.递归相邻格子
    for (auto v : dir) {    // 向四个方向搜索
        int x_next = x_cur + v.first;
        int y_next = y_cur + v.second;
        if (x_next < 0 || y_next < 0 ||
            x_next > map.size() - 1 || y_next > map[0].size() - 1) continue; // 越界
        if (map[x_next][y_next] == 1 && visited[x_next][y_next] == false) {
            squre += dfs(map, visited, x_next, y_next, valid);  // 记录以当前格子为出发点的总面积
        }
    }
    return squre;
}

int main() {
    // 输入并初始化
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // 遍历地图，深搜格子所在岛屿
    int total_squre = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 || visited[i][j] == true) continue;  // 水域或者已访问
            // 深搜格子所在岛屿，返回陆地格子数（面积）和是否有效
            int valid = 1;
            int squre = dfs(map, visited, i, j, valid); // 若在深搜过程中发现触碰边界，会以引用的形式返回 valid = 0
            total_squre += squre * valid;               // 触碰边界的岛屿结果无效
        }
    }

    cout << total_squre << endl;

    return 0;
}