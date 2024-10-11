#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string path;                    // 路径
    // vector<vector<int>> last;    // 路径中每个集合的靠后的元素索引
    vector<string> result;          // 结果
    vector<string> alpha = {"", "abc", "def", 
                            "ghi", "jkl", "mno",
                            "pqrs", "tuv", "wxyz"};

    void backtracking(string digits, int depth) {
        if (path.size() == digits.size()) {         // 终止条件（到达叶子节点）
            result.push_back(path);
            return;
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        int num = digits[depth] - '1';
        int startIndex = 0;                 // 默认从本集合第一个元素开始
        // if (!last[num].empty()) { // 若路径中有本集合元素出现，重新计算
        //     startIndex = last[num].back();
        // }

        for (int i = startIndex; i < alpha[num].size(); i++) {
            path.push_back(alpha[num][i]);    // 处理节点，记录路径
            // last[num].push_back(i);
            backtracking(digits, depth + 1);    // 递归：控制树的纵向遍历，
                                                //     注意下一层搜索要从i+1开始
            path.pop_back();                    // 回溯，撤销处理的节点
            // last[num].pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // last.resize(9);
        path.clear();
        result.clear();
        if (0 == digits.size()) return result;
        backtracking(digits, 0);
        return result;
    }
};

int main() {
    Solution s;

    string str = "22";
    
    vector<string> result = s.letterCombinations(str);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}