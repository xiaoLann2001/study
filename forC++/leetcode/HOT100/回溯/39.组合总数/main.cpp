#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(path);
            return;
        }

        // 为避免重复，保证下一层的的下标>=上一层
        for (int i = startIndex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> input = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ret = s.combinationSum(input, target);

    for (const auto& v : ret) {
        for (const auto& n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}