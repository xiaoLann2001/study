#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> first, vector<int> second) {
        return first[0] < second[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        int right_bound = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= right_bound) right_bound = intervals[i][1];
            else {
                right_bound = min(right_bound, intervals[i][1]);
                result++;
            }
        }
        return result;
    }
};

class Solution1 {
public:
    static bool cmp(vector<int> first, vector<int> second) {
        return first[1] < second[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 1; // 记录非重叠区间
        int right_bound = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= right_bound) {
                result++;
                right_bound = intervals[i][1];
            }
        }
        return intervals.size() - result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    int result = s.eraseOverlapIntervals(intervals);

    cout << result << endl;

    return 0;
}