#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

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
            // 广搜格子所在岛屿，记录陆地格子数（面积）
            int squre = 0;
            queue<pair<int, int>> queue_next;
            queue_next.push(pair<int, int>(i, j));
            visited[i][j] = true;   // 标记当前格子已访问
            squre++;    // 面积加一
            while (!queue_next.empty()) {
                int x_cur = queue_next.front().first;
                int y_cur = queue_next.front().second;
                queue_next.pop();
                for (auto v : dir) {
                    int x_next = x_cur + v.first;
                    int y_next = y_cur + v.second;
                    if (x_next < 0 || y_next < 0 ||
                        x_next > n - 1 || y_next > m - 1) continue; // 越界
                    if (map[x_next][y_next] == 1 && visited[x_next][y_next] == false) {
                        queue_next.push(pair<int, int>(x_next, y_next));
                        visited[x_next][y_next] = true; // 标记当前格子已访问
                        squre++;    // 面积加一
                    }
                }
            }
            max_squre = max(max_squre, squre);
        }
    }

    cout << max_squre << endl;

    return 0;
}