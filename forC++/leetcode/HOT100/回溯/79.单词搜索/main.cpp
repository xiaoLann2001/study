#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& board, string& word, int idx, int r, int c) {
        if (idx == word.size()) return true;  // 单词匹配完成
        if (r < 0 || c < 0 || r >= m || c >= n) return false;  // 越界
        if (visited[r][c] || board[r][c] != word[idx]) return false; // 已访问或字符不符

        visited[r][c] = true;
        for (auto d : dirs) {
            if (dfs(board, word, idx + 1, r + d.first, c + d.second)) return true;
        }
        visited[r][c] = false; // 回溯
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    cout << (s.exist(board, "ABCCED") ? "true" : "false") << endl; // true
    cout << (s.exist(board, "SEE") ? "true" : "false") << endl;    // true
    cout << (s.exist(board, "ABCB") ? "true" : "false") << endl;   // false
}
