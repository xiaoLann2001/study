#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    bool isVaild(int n, int row, int col, vector<string> &chessboard) {
        // 不能同行，使用回溯确保了棋子一行只能选一个
        // 不能同列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 不能同斜线，45度，135度，向上检查
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    // 参数：棋盘行数（列数），行号，棋盘字符串数组
    void backtracking(int n, int row, vector<string> &chessboard) {
        // 终止条件，行号等于n
        if (n == row) {
            result.push_back(chessboard);
            return;
        }

        // 遍历本行的所有列
        for (int col = 0; col < n; col++) {
            // 若格子行列号符合条件
            if (isVaild(n, row, col, chessboard)) {
                chessboard[row][col] = 'Q';     // 放置皇后
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';     // 回溯，撤销皇后
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main() {
    Solution s;

    int n = 4;

    vector<vector<string>> result = s.solveNQueens(n);

    for (vector<string> vec : result) {
        for (string str : vec) {
            cout << str << endl;
        }
        cout << endl;
    }

    return 0;
}