#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(const vector<vector<int>> &map, vector<vector<bool>> &visited, int i, int j, int &valid) {
    int squre = 0;
    queue<pair<int, int>> queue_next;
    queue_next.push(pair<int, int>(i, j));
    visited[i][j] = true;   // 标记当前格子已访问
    while (!queue_next.empty()) {
        int x_cur = queue_next.front().first;
        int y_cur = queue_next.front().second;
        queue_next.pop();
        squre++;    // 面积加一（最终岛屿所有格子都会弹出，所以在弹出时计数和检查）
        if (x_cur == 0 || y_cur == 0 || // 碰到边界，标记无效
            x_cur == map.size() - 1 || y_cur == map[0].size() - 1) valid = 0;
        for (auto v : dir) {
            int x_next = x_cur + v.first;
            int y_next = y_cur + v.second;
            if (x_next < 0 || y_next < 0 || // 越界
                x_next > map.size() - 1 || y_next > map[0].size() - 1) continue;
            if (map[x_next][y_next] == 1 && visited[x_next][y_next] == false) {
                queue_next.push(pair<int, int>(x_next, y_next));
                visited[x_next][y_next] = true; // 标记当前格子已访问
            }
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

    int total_squre = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 || visited[i][j] == true) continue;  // 水域或者已访问
            // 广搜格子所在岛屿，记录陆地格子数（面积）
            int valid = 1;  // 若不为孤岛，标记为 0，最后统计面积乘以 0
            int squre = bfs(map, visited, i, j, valid);
            total_squre += squre * valid;
        }
    }

    cout << total_squre << endl;

    return 0;
}