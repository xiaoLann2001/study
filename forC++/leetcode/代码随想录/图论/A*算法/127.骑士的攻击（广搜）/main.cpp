#include <bits/stdc++.h>

using namespace std;

#define MIN_X 1
#define MIN_Y 1
#define MAX_X 1000
#define MAX_Y 1000

const vector<vector<int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                 {-2, -1}, {-1, -2}, {1, -2}, {2, -1}}; // 骑士规则

int n;

bool isInBox(int x, int y) {
    return x >= MIN_X && y >= MIN_Y && x <= MAX_X && y <= MAX_Y;
}

// 广搜
int BFS(int x_start, int y_start, int x_end, int y_end) {
    int result = 0, count_pre, count_cur;
    int x_cur, y_cur, x_next, y_next;
    queue<pair<int, int>> que;
    vector<vector<bool>> visited(MAX_X + 1, vector<bool>(MAX_Y + 1, false));
    // 先将起点压入栈
    que.push(pair<int, int>{x_start, y_start});
    visited[x_start][y_start] = true;
    count_pre = 1;
    count_cur = 0;
    while (!que.empty()) {
        // 当前格子
        x_cur = que.front().first;
        y_cur = que.front().second;
        que.pop();
        // 检查是否为终点
        if (x_cur == x_end && y_cur == y_end) {
            while (!que.empty()) que.pop();
            break;
        }
        // 下一步能走的格子
        for (vector<int> v : dir) {
            x_next = x_cur + v[0];
            y_next = y_cur + v[1];
            // 检查是否越界
            if (!isInBox(x_next, y_next)) continue;
            // 加入队列
            if (!visited[x_next][y_next]) {
                que.push(pair<int, int>{x_next, y_next});
                visited[x_next][y_next] = true;
                count_cur++;    // 记录新加入队列的元素个数
            }
        }
        // 轮次统计
        count_pre--;                // 队列中本轮元素个数减一
        if (count_pre == 0) {       // 若本轮所有元素弹出，那么更新轮次并重新统计
            result++;               // 最终路径加一
            count_pre = count_cur;  // 本轮需要弹出的元素更新
            count_cur = 0;          // 重新统计新加入的元素个数
        }
    }
    return result;
}

int main() {
    int a1, a2, b1, b2;
    cin >> n;
    while (n--) {
        cin >> a1 >> a2 >> b1 >> b2;
        cout << BFS(a1, a2, b1, b2) << endl;
    }

    return 0;
}