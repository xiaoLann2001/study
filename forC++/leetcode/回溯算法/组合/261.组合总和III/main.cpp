#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    int sum;                        // 总和
    vector<vector<int>> result;         // 结果
    int count = 0;

    // n-目标总和，k-数字个数，startIndex-起始数字
    void backtracking(int n, int k, int startIndex) {
        count++;
        cout << "递归次数：" << count << endl;
        // if (sum > n) return;     // 终止条件（剪枝）
        
        if (path.size() == k && sum == n) {         // 终止条件（到达叶子节点）
            result.push_back(path);
            return;
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        // 1 <= i <= 9
        for (int i = startIndex; i <= 9 - k + path.size() + 1; i++) {   // 剪枝
            // 因为对总和的剪枝可能在循环中间，所以不能放到循环判断条件里面
            // 而对元素个数的剪枝一定在右侧，所以可以放在循环判断条件里面
            if (n - sum - i >= 
                (k - path.size() - 1) * (i + 0.5 * (k - path.size())) && 
                n - sum - i <= 
                (k - path.size() - 1) * (10 - 0.5 * (k - path.size()))) 
            {
                path.push_back(i);          // 处理节点，记录路径
                sum += i;
                backtracking(n, k, i + 1);  // 递归：控制树的纵向遍历，
                                            //     注意下一层搜索要从i+1开始
                path.pop_back();            // 回溯，撤销处理的节点
                sum -= i;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        path.clear();
        result.clear();
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution s;

    int k = 3;
    int n = 7;
    
    vector<vector<int>> result = s.combinationSum3(k, n);

    for (vector<int> v : result) {
        for (int n : v) {
            cout << n << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}