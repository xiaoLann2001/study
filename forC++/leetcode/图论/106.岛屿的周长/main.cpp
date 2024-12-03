#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<vector<int>> grid;       // 地图矩阵
vector<vector<int>> visited;    // 已访问格子

void dfs(int x_cur, int y_cur, int &num_shore) {
    // 处理当前节点
    visited[x_cur][y_cur] = 1;  // 标记已访问
    // 处理相邻节点
    for (auto v : dir) {
        int x_next = x_cur + v.first;
        int y_next = y_cur + v.second;
        if (x_next < 0 || y_next < 0 || x_next >= n || y_next >= m) {
            num_shore++;   // 遇到边界水
            continue;       // 越界
        }
        if (grid[x_next][y_next] == 0) num_shore++; // 遇到非边界水
        else if (visited[x_next][y_next] == 0) {    // 访问未访问的陆地
            dfs(x_next, y_next, num_shore);
        }
    }
}

void bfs(int x_start, int y_start, int &num_shore) {
    queue<pair<int, int>> queue_next;
    queue_next.push(pair<int, int>(x_start, y_start));
    visited[x_start][y_start] = 1;  // 标记已访问
    while (!queue_next.empty()) {
        // 当前节点
        int x_cur = queue_next.front().first;
        int y_cur = queue_next.front().second;
        queue_next.pop();
        for (auto v : dir) {
            int x_next = x_cur + v.first;
            int y_next = y_cur + v.second;
            if (x_next < 0 || y_next < 0 || x_next >= n || y_next >= m) {
                num_shore++;   // 遇到边界水
                continue;       // 越界
            }
            if (grid[x_next][y_next] == 0) num_shore++; // 遇到非边界水
            else if (visited[x_next][y_next] == 0) {    // 访问未访问的陆地
                queue_next.push(pair<int, int>(x_next, y_next));
                visited[x_next][y_next] = 1;    // 标记已访问
            }
        }
    }
}

int main() {
    // 输入并初始化
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 搜索并记录海岸数
    int num_shore = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0 || visited[i][j] == 1) continue;    // 水或者已访问
            // dfs(i, j, num_shore);
            bfs(i, j, num_shore);
        }
    }

    cout << num_shore << endl;

    return 0;
}