#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    vector<vector<int>> result;         // 结果

    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if (startIndex >= nums.size()) {         // 终止条件（到达叶子节点）
            return;
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        for (int i = startIndex; i < nums.size(); i++) {   // 剪枝
            if (i > startIndex && nums[i] == nums[i - 1]) continue; // 去重
            path.push_back(nums[i]);    // 处理节点，记录路径
            backtracking(nums, i + 1);  // 递归：控制树的纵向遍历，
                                        //     注意下一层搜索要从i+1开始
            path.pop_back();            // 回溯，撤销处理的节点
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {4,4,4,1,4};
    
    vector<vector<int>> result = s.subsetsWithDup(nums);

    for (vector<int> v : result) {
        cout << "[ ";
        for (int n : v) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}