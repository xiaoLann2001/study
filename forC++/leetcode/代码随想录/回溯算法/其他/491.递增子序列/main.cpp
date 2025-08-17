#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    vector<vector<int>> result;         // 结果

    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() >= 2) result.push_back(path);
        if (startIndex >= nums.size()) {         // 终止条件（到达叶子节点）
            return;
        }

        bool hash[201] = {false};             // 记录树层元素使用情况

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        for (int i = startIndex; i < nums.size(); i++) {   // 剪枝
            // 树层去重，用bool型used数组记录同一树层元素是否使用过
            if (hash[nums[i] + 100]) 
                continue;
            // 保证递增
            if (startIndex > 0 && nums[i] < nums[startIndex - 1]) 
                continue;
            path.push_back(nums[i]);    // 处理节点，记录路径
            hash[nums[i] + 100] = true;
            backtracking(nums, i + 1);  // 递归：控制树的纵向遍历，
                                        //     注意下一层搜索要从i+1开始
            path.pop_back();            // 回溯，撤销处理的节点
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {4,6,7,7};
    
    vector<vector<int>> result = s.findSubsequences(nums);

    for (vector<int> v : result) {
        cout << "[ ";
        for (int n : v) {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}