#include <bits/stdc++.h>

using namespace std;

// 四个方向
const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 深度优先搜索
void dfs(vector<vector<int>> &map, vector<vector<int>> &status, int x, int y, int group_num) {
    // 处理当前格子
    status[x][y] += group_num;   // 状态转移
    // 相邻格子
    for (auto v : dir) {
        int x_next = x + v.first;
        int y_next = y + v.second;
        if (x_next < 0 || y_next < 0 || // 越界
            x_next > map.size() - 1 || y_next > map[0].size() - 1) continue;
        // 不符合条件，跳过处理当前格子
        if (status[x_next][y_next] == group_num || status[x_next][y_next] >= 3) continue;
        if (map[x_next][y_next] >= map[x][y]) { // “水往高处流”
            dfs(map, status, x_next, y_next, group_num);
        }
    }
}

int main() {
    // 输入并初始化
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    // status: 0-未到达，1-第一组边界到达，2-第二组边界到达，3-两组边界同时到达
    vector<vector<int>> status(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // 采用深度优先搜索
    // 遍历第一组边界
    for (int i = 0; i < map.size(); i++) {
        if (status[i][0] != 1 && status[i][0] < 3) dfs(map, status, i, 0, 1);
    }
    for (int j = 0; j < map[0].size(); j++) {
        if (status[0][j] != 1 && status[0][j] < 3) dfs(map, status, 0, j, 1);
    }

    // 遍历第二组边界
    for (int i = 0; i < map.size(); i++) {
        if (status[i][m - 1] != 2 && status[i][m - 1] < 3) dfs(map, status, i, m - 1, 2);
    }
    for (int j = 0; j < map[0].size(); j++) {
        if (status[n - 1][j] != 2 && status[n - 1][j] < 3) dfs(map, status, n - 1, j, 2);
    }

    // 打印状态数组
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << status[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 输出被标记两遍的格子坐标
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (status[i][j] == 3) cout << i << " " << j << endl;
        }
    }

    return 0;
}