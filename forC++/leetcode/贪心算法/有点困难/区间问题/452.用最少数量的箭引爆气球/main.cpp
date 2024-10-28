#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        
        // 按左边界升序排序
        sort(points.begin(), points.end(), cmp);

        // 从左往右遍历气球
        int result = 1;
        int right_bound = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > right_bound) {
                result++;
                right_bound = points[i][1];
            } 
            else {
                right_bound = min(right_bound, points[i][1]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    int result = s.findMinArrowShots(points);

    cout << result << endl;

    return 0;
}