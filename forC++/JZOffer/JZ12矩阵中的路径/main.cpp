#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // 深度优先搜索
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool> > is_visited(n, vector<bool>(m, false));
        // 先在矩阵中找到起点
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == word[0]) {
                    for (int k = 0; k < n; ++k) fill(is_visited[k].begin(), is_visited[k].end(), false);    // 清零，不会重新分配空间
                    // is_visited.assign(n, vector<bool>(m, false));   // 清零用assign()，会重新分配空间并初始化
                    // is_visited.resize(n, vector<bool>(m, false));   // 为什么没有清0：当容器大小不变时，resize不会有作用
                    // for (const auto& v : is_visited) {
                    //     for (const auto& n : v) cout << n << " ";
                    //     cout << endl;
                    // }
                    // cout << endl;
                    is_visited[i][j] = true;
                    if (dfs(matrix, is_visited, word, 0, i, j)) {
                        return true;    // 找到路径
                    }
                } 
            }
        }
        return false;   // 未找到路径
    }

    const vector<pair<int, int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右

    bool dfs(vector<vector<char> >& matrix, vector<vector<bool> >& is_visited, string word, int idx, int xcur, int ycur) {
        // cout << "xcur:" << xcur << "\tycur: " << ycur << endl;
        // for (const auto& v : is_visited) {
        //     for (const auto& n : v) cout << n << " ";
        //     cout << endl;
        // }
        // cout << endl;
        if (idx >= word.size() - 1) return true;    // 已经找到一条路径，快速返回
        for (const auto& p : direct) {  // 向四个方向搜索
            int xnext = xcur + p.first;
            int ynext = ycur + p.second;
            if (xnext < 0 || ynext < 0 || xnext >= matrix.size() || ynext >= matrix[0].size()) continue;   // 越界
            if (!is_visited[xnext][ynext]) {
                if (matrix[xnext][ynext] == word[idx + 1]) {
                    is_visited[xnext][ynext] = true;
                    if (dfs(matrix, is_visited, word, idx + 1, xnext, ynext)) {
                        return true;    // 快速返回
                    }
                    is_visited[xnext][ynext] = false;   // 回溯
                }
            } 
        }
        return false;   // 返回继续搜索
    }
};

int main() {
    Solution s;

    vector<vector<char>> matrix = {
        {'A','B','C','E','H','J','I','G'},
        {'S','F','C','S','L','O','P','Q'},
        {'A','D','E','E','M','N','O','E'},
        {'A','D','I','D','E','J','F','M'},
        {'V','C','E','I','F','G','G','S'}
    };
    string word = "SGGFIECVAASABCEHJIGQEM";

    bool ret = s.hasPath(matrix, word);

    cout << ret << endl;

    return 0;
}