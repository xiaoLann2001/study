#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    vector<bool> used;                  // 记录树枝元素使用情况
    vector<vector<int>> result;         // 结果

    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() >= nums.size()) {   // 终止条件（到达叶子节点）
            result.push_back(path);
            return;
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;      // 跳过树枝中已经选择的元素
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) 
                continue;   // 树层去重
            path.push_back(nums[i]);    // 处理节点，记录路径
            used[i] = true;
            backtracking(nums, used);   // 递归：控制树的纵向遍历，
                                        //     注意下一层搜索要从i+1开始
            path.pop_back();            // 回溯，撤销处理的节点
            used[i] = false;
            count++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        result.clear();
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1,1,2};
    
    vector<vector<int>> result = s.permuteUnique(nums);

    for (vector<int> v : result) {
        cout << "[ ";
        for (int n : v) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}