#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 先二分查找确定行，再二分查找确定列
        // 找满足 matrix[mid][0] <= target 的最大值，闭区间
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right < 0) return false;  // 特殊情况：target 比所有行首都小

        cout << right << endl;

        // 找特定值，闭区间
        int row = right;
        left = 0;
        right = matrix[row].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[row][mid] < target) {
                left = mid + 1;
            } else if (matrix[row][mid] > target){
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 3;

    bool ret = s.searchMatrix(matrix, target);

    cout << ret << endl;

    return 0;
}