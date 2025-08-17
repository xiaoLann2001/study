#include <bits/stdc++.h>

using namespace std;

// 四个方向
const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 深度优先搜索
void dfs(vector<vector<int>> &map, vector<vector<int>> &map_copy, int x, int y) {
    // 处理当前节点
    map[x][y] = 0;
    map_copy[x][y] = 1;
    // 递归相邻节点
    for (auto v : dir) {
        int x_next = x + v.first;
        int y_next = y + v.second;
        if (x_next < 0 || y_next < 0 || // 越界
            x_next > map.size() - 1 || y_next > map[0].size() - 1) continue;
        if (map[x_next][y_next] == 1) {
            dfs(map, map_copy, x_next, y_next);
        }
    }
}

int main() {
    // 输入并初始化
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> map_copy(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    // 采用深度优先搜索
    // 遍历左右两侧的边缘
    for (int i = 0; i < map.size(); i++) {
        if (map[i][0] == 1) dfs(map, map_copy, i, 0);
        if (map[i][m - 1] == 1) dfs(map, map_copy, i, m - 1);
    }

    // 遍历上下两侧的边缘
    for (int j = 0; j < map[0].size(); j++) {
        if (map[0][j] == 1) dfs(map, map_copy, 0, j);
        if (map[n - 1][j] == 1) dfs(map, map_copy, n - 1, j);
    }

    // 输出将孤岛“沉没”之后的岛屿矩阵。 注意：每个元素后面都有一个空格
    for (auto v : map_copy) {
        for (auto n : v) cout << n << " ";
        cout << endl;
    }

    return 0;
}