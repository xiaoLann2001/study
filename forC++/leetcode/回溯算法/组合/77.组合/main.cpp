#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    vector<vector<int>> result;         // 结果

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {         // 终止条件（到达叶子节点）
            result.push_back(path);
            return;
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        // for (int i = startIndex; i <= n; i++) {
        for (int i = startIndex; i <= n - k + path.size() + 1; i++) {   // 剪枝
            path.push_back(i);          // 处理节点，记录路径
            backtracking(n, k, i + 1);  // 递归：控制树的纵向遍历，
                                        //     注意下一层搜索要从i+1开始
            path.pop_back();            // 回溯，撤销处理的节点
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution s;

    int n = 4;
    int k = 2;
    
    vector<vector<int>> result = s.combine(n, k);

    for (vector<int> v : result) {
        for (int n : v) {
            cout << n << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}