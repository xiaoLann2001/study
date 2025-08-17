#include <bits/stdc++.h>

using namespace std;

// 图 vector<vector<int>>，初始化时将陆地标记为 1，水域为 0

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};   // 四个方向

void dfs(vector<vector<int>> &map, int x_cur, int y_cur) {
    // 终止条件
    if (map[x_cur][y_cur] == 0) return;
    // 标记当前格子
    map[x_cur][y_cur] = 0;
    for (auto v : dir) {
        int x_next = x_cur + v.first;
        int y_next = y_cur + v.second;
        if (x_next < 0 || y_next < 0 || x_next > map.size() - 1 || y_next > map[0].size() - 1) continue; // 越界
        if (map[x_next][y_next] == 1) {
            dfs(map, x_next, y_next);   // 继续搜索新的分支
        }
    }
}

int main() {
    // input and initiate
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) continue;   // 若为水域或者已标记，跳过
            // 发现陆地，将陆地所在岛屿全部标记
            dfs(map, i, j);
            count++;    // 标记完一个岛屿，计数加一
        }
    }

    cout << count << endl;

    return 0;
}