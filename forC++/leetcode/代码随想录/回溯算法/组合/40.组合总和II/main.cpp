#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    int sum;                            // 总和
    vector<vector<int>> result;         // 结果
    int count = 0;

    // candidates-备选集合，target-目标总和，startIndex-起始数字
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        count++;
        cout << "递归次数：" << count << endl;
        
        if (sum == target) {        // 终止条件（到达叶子节点）
            result.push_back(path);
            return;
        }
        // if (sum > target) {         // 剪枝 
        //     return;
        // }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        for (int i = startIndex; i < candidates.size() &&
                                 candidates[i] <= target - sum; i++) {   // 剪枝
            if (i > startIndex && candidates[i] == candidates[i -1]) continue;
            path.push_back(candidates[i]);          // 处理节点，记录路径
            sum += candidates[i];
            backtracking(candidates, target, i + 1);// 递归：控制树的纵向遍历，
                                                // 注意下一层搜索要从i+1开始
            path.pop_back();                    // 回溯，撤销处理的节点
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sum = 0;
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    
    vector<vector<int>> result = s.combinationSum2(candidates, target);

    for (vector<int> v : result) {
        for (int n : v) {
            cout << n << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}