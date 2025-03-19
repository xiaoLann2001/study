#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右

    int movingCount(int threshold, int rows, int cols) {
        // 因为机器人只能一个一个走，要在原来的基础向外尝试，用搜索算法（dfs/bfs）
        // 这里使用 bfs 算法
        int count = 0;
        queue<pair<int, int>> reachable_que;
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        reachable_que.push({0, 0});
        is_visited[0][0] = true;
        while (!reachable_que.empty()) {
            pair<int, int> cur = reachable_que.front();
            reachable_que.pop();
            count++;
            int xcur = cur.first;
            int ycur = cur.second;

            for (const auto& p : direct) {  // 向四个方向搜索
                int xnext = xcur + p.first;
                int ynext = ycur + p.second;
                if (xnext < 0 || ynext < 0 || xnext >= rows || ynext >= cols) continue;   // 越界
                if (!is_visited[xnext][ynext]) {
                    if (sum_digits(xnext) + sum_digits(ynext) <= threshold) {   // 如果未访问且满足阈值条件，加入队列并标记为已访问
                        is_visited[xnext][ynext] = true;
                        reachable_que.push({xnext, ynext});
                    }
                }
            }
        }
        return count;
    }

    int sum_digits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution s;

    int th = 10, 
        rows = 50, 
        cols = 50;
    
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         if (s.sum_digits(i) + s.sum_digits(j) <= th) {
    //             // cout << "#" << " ";
    //             cout << "\033[47m\033[30m" << "#" << " " << "\033[0m";
    //         } else cout << "\033[47m\033[30m" << "." << " " << "\033[0m";
    //     }
    //     cout << endl;
    // }

    int ret = s.movingCount(th, rows, cols);

    cout << ret << endl;

    return 0;
}