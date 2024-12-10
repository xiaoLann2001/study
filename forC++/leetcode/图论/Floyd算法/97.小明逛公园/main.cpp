#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<vector<vector<int>>> grid;

int main() {
    // 输入并初始化
    int u, v, w, start, end;
    cin >> n >> m;
    grid.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10001)));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        grid[u][v][0] = w;  // 双向图
        grid[v][u][0] = w;
    }

    // grid数组对角线置0
    for (int i = 1; i <= n; i++) grid[i][i][0] = 0;

    // Floyd算法
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);
            }
        }
    }

    // 输出任意观景计划的结果
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        if (grid[start][end][n] != 10001) cout << grid[start][end][n] << endl;
        else cout << -1 << endl;
    }

    return 0;
}