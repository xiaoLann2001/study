#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int _n;
    vector<vector<string>> result;
    vector<int> cols;
    vector<bool> used;

    // 检查是否满足不在同一斜线的条件
    bool check(int n) {
        for (int i = 1; i <= cols.size(); i++) {
            if (cols[cols.size() - i] == (n - i) || cols[cols.size() - i] == (n + i)) return false;
        }
        return true;
    }

    void backtracking() {
        // 保存结果
        if (cols.size() == _n) {
            vector<string> grid(_n, string(_n, '.'));
            for (int i = 0; i < _n; i++) {
                grid[i][cols[i]] = 'Q';
            }
            result.push_back(grid);
        }

        for (int i = 0; i < _n; i++) {
            if (used[i] || !check(i)) continue;
            used[i] = true;
            cols.push_back(i);
            backtracking();
            cols.pop_back();    // 回溯
            used[i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        result.clear();
        cols.clear();
        used.resize(n, false);
        backtracking();
        return result;
    }
};

int main() {
    Solution s;

    int n = 4;

    vector<vector<string>> ret = s.solveNQueens(n);

    for (auto v : ret) {
        for (auto str : v) cout << str << endl;
        cout << endl;
    }

    return 0;
}