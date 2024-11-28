#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(const vector<vector<int>> &map, vector<vector<bool>> &visited, int x_cur, int y_cur) {
    // 终止条件：遇到水域或者已访问的格子
    if (map[x_cur][y_cur] == 0 || visited[x_cur][y_cur] == true) return 0;
    visited[x_cur][y_cur] = true;   // 标记已访问
    int squre = 1;  // 当前访问元素面积为1
    for (auto v : dir) {    // 向四个方向搜索
        int x_next = x_cur + v.first;
        int y_next = y_cur + v.second;
        if (x_next < 0 || y_next < 0 ||
            x_next > map.size() - 1 || y_next > map[0].size() - 1) continue; // 越界
        if (map[x_next][y_next] == 1 && visited[x_next][y_next] == false) {
            squre += dfs(map, visited, x_next, y_next);
        }
    }
    return squre;
}

int main() {
    // input and initiate
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int max_squre = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 || visited[i][j] == true) continue;  // 水域或者已访问
            // 深搜格子所在岛屿，返回陆地格子数（面积）
            max_squre = max(max_squre, dfs(map, visited, i, j));
        }
    }

    cout << max_squre << endl;

    return 0;
}