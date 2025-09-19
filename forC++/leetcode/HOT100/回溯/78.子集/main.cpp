#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() <= nums.size()) {
            result.push_back(path);
            return;
        }

        // 为避免重复，保证下一层的起始下标>上一层
        for (int i = startIndex; i < nums.size(); i++) {
            if (!used[i]) {         // 路径去重
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, i + 1);  // 用startIndex剪枝
                path.pop_back();    // 回溯
                used[i] = false;
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return result;
        used.resize(nums.size(), false);
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> input = {1, 2, 3};

    vector<vector<int>> ret = s.subsets(input);

    for (const auto& v : ret) {
        for (const auto& n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}