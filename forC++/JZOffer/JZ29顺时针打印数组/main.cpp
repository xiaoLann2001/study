#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        // 边长为 nxm 的圈，从左上角开始，需要打印 2 次 n - 1 长度的数组，2 次 m - 1 长度的数组
        // 每一圈（即使不是圈）开始的位置都是 (i, i)，i <= min(n / 2, m / 2)
        // （注意！！！题目没有说是方形的）
        vector<int> flatenedArray;
        int n = matrix.size();
        if (n == 0) 
            return flatenedArray;
        int m = matrix[0].size();
        
        // 最多有 min((n - 1) / 2, (m - 1) / 2) 个起点
        for (int start = 0; start <= min((n - 1) / 2, (m - 1) / 2); start++) {
            traversal(matrix, flatenedArray, start, n - start * 2, m - start * 2);
        }
        
        return flatenedArray;
    }

    /**
     * 遍历一次外圈，将结果附加到 flatenedArray 后
     * start，遍历开始的位置(start, start)
     * n 遍历的圈的高度
     * m 遍历的圈的宽度
    */
    void traversal(const vector<vector<int> >& matrix, vector<int>& flatenedArray, int start, int n, int m) {
        const vector<pair<int, int>> direct = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 顺时针：右下左上
        vector<int> increase = {m - 1, n - 1, m - 1, n - 1};
        int x = start, y = start;

        // 只有一行或一列
        if (n == 1) {
            for (int j = 0; j < m; j++) {
                flatenedArray.push_back(matrix[x][y]);
                x += direct[0].first;
                y += direct[0].second;
            }
            return;
        } else if (m == 1) {
            for (int j = 0; j < n; j++) {
                flatenedArray.push_back(matrix[x][y]);
                x += direct[1].first;
                y += direct[1].second;
            }
            return;
        }

        // 有完整的一圈
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < increase[i]; j++) {
                flatenedArray.push_back(matrix[x][y]);
                x += direct[i].first;
                y += direct[i].second;
            }
        }
    }
};

int main() {
    Solution s;

    // vector<vector<int>> matrix = {{1,2,3,4},
    //                               {5,6,7,8},
    //                               {9,10,11,12},
    //                               {13,14,15,16}};
    // vector<vector<int>> matrix = {{1,2,3},
    //                               {4,5,6},
    //                               {7,8,9}};
    vector<vector<int>> matrix = {{1,2,3,4,5},
                                  {6,7,8,9,10}};
    // vector<vector<int>> matrix;

    vector<int> ret = s.printMatrix(matrix);

    for (const auto& n : ret) cout << n << " ";
    cout << endl;

    return 0;
}