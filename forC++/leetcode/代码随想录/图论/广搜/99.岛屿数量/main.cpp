#include <bits/stdc++.h>

using namespace std;

// 图 vector<vector<int>>，初始化时将陆地标记为 1，水域为 0
// 队列 queue<int, int> 记录下一圈要访问的格子

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

    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};   // 四个方向

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) continue;   // 若为水域或者已标记，跳过
            // 发现陆地，将陆地所在岛屿全部标记
            queue<pair<int, int>> queue_next;
            queue_next.push(pair<int, int>(i, j));
            while (!queue_next.empty()) {
                // 当前位置
                int x_cur = queue_next.front().first;
                int y_cur = queue_next.front().second;
                queue_next.pop();
                // 向四周扩散
                for (auto v : dir) {
                    int x_next = x_cur + v.first;
                    int y_next = y_cur + v.second;
                    if (x_next < 0 || y_next < 0 || x_next > n - 1 || y_next > m - 1) continue; // 越界
                    if (map[x_next][y_next] == 1) {
                        queue_next.push(pair<int, int>(x_next, y_next));// 记录下圈要访问的陆地
                        map[x_next][y_next] = 0;   // 将陆地标记为水域表示已访问
                    }
                }
            }
            count++;    // 标记完一个岛屿，计数加一
        }
    }

    cout << count << endl;

    return 0;
}