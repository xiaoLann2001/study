#include <bits/stdc++.h>

using namespace std;

// 四个方向
const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 广度优先搜索
void bfs(vector<vector<int>> &map, vector<vector<int>> &status, int x, int y, int group_num) {
    queue<pair<int, int>> queue_next;
    queue_next.push(pair<int, int>(x, y));
    while (!queue_next.empty()) {
        // 当前格子
        int x_cur = queue_next.front().first;
        int y_cur = queue_next.front().second;
        queue_next.pop();
        // 不符合条件，跳过处理当前格子
        if (status[x_cur][y_cur] == group_num || status[x_cur][y_cur] >= 3) continue;
        // 处理当前格子
        status[x_cur][y_cur] += group_num;   // 状态转移
        // 相邻格子
        for (auto v : dir) {
            int x_next = x_cur + v.first;
            int y_next = y_cur + v.second;
            if (x_next < 0 || y_next < 0 || // 越界
                x_next > map.size() - 1 || y_next > map[0].size() - 1) continue;
            if (map[x_next][y_next] >= map[x_cur][y_cur]) { // “水往高处流”
                queue_next.push(pair<int, int>(x_next, y_next));
            }
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

    // 采用广度优先搜索
    // 遍历第一组边界
    for (int i = 0; i < map.size(); i++) {
        if (status[i][0] != 1 && status[i][0] < 3) bfs(map, status, i, 0, 1);
    }
    for (int j = 0; j < map[0].size(); j++) {
        if (status[0][j] != 1 && status[0][j] < 3) bfs(map, status, 0, j, 1);
    }

    // 遍历第二组边界
    for (int i = 0; i < map.size(); i++) {
        if (status[i][m - 1] != 2 && status[i][m - 1] < 3) bfs(map, status, i, m - 1, 2);
    }
    for (int j = 0; j < map[0].size(); j++) {
        if (status[n - 1][j] != 2 && status[n - 1][j] < 3) bfs(map, status, n - 1, j, 2);
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