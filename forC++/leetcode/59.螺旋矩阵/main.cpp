// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

// 示例 1：


// 输入：n = 3
// 输出：[[1,2,3],[8,9,4],[7,6,5]]
// 示例 2：

// 输入：n = 1
// 输出：[[1]]
 

// 提示：

// 1 <= n <= 20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printM(vector<vector<int>> v) {
    std::cout << "[";
    for_each(v.begin(), v.end(), [](vector<int> vv) {
        std::cout << "[";
        for_each(vv.begin(), vv.end(), [](int val) {
            std::cout << val << ",\t";
        });
        std::cout << "]," << endl;
    });
    std::cout << "]" << endl << endl;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int val = 0;
        for (int cur_n = n; cur_n >= 1; cur_n -= 2) {   // 循环一轮后当前矩阵大小-2
            // 起始元素一定在左上角
            int layer = (n - cur_n) / 2;
            if (cur_n == 1) {
                m[layer][layer] = ++val;
                break;
            }
            int row = layer;    // 记录行索引
            int col = layer;    // 记录列索引
            while (col < n - 1 - layer) {
                m[row][col] = ++val;
                col++;
            }

            while (row < n - 1 - layer) {
                m[row][col] = ++val;
                row++;
            }

            while (col > layer) {
                m[row][col] = ++val;
                col--;
            }

            while (row > layer) {
                m[row][col] = ++val;
                row--;
            } 

        }

        return m;
    }
};

int main(){
    Solution s;

    int n = 6;

    printM(s.generateMatrix(n));

    return 0;
}