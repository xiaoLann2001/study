#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {      // 去重
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums);
                path.pop_back();    // 回溯
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return result;
        used.resize(nums.size(), false);
        backtracking(nums);
        return result;
     }
};

int main() {
    Solution s;

    vector<int> input = {1, 2, 3};

    vector<vector<int>> ret = s.permute(input);

    for (const auto& v : ret) {
        for (const auto& n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}