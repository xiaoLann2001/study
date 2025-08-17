#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> l, vector<int> r) {
            return l[0] < r[0];
        });

        vector<vector<int>> result;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (auto v : intervals) {
            if (v[0] > right) {
                result.push_back(vector<int>{left, right});
                right = v[1];
                left = v[0];
            } else {
                right = max(right, v[1]);
            }
        }
        result.push_back(vector<int>{left, right});
        return result;
    }
};

int main() {
    Solution s;

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = s.merge(intervals);

    cout << "[ ";
    for (const auto v : result) {
        cout << "[ ";
        for (const auto n : v) {
            cout << n << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;;

    return 0;
}