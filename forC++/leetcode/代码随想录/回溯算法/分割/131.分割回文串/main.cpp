#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> path;                // 路径
    vector<vector<string>> result;      // 结果

    // 判断是不是回文串，参数字符串，起始位置，结束位置，左闭右闭
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right && s[left] == s[right]) {
            left++; 
            right--;
        }
        if (left < right) return false;
        return true;
    }

    void backtracking(const string &s, int startIndex) {
        if (startIndex == s.size()) {   // 终止条件（到达叶子节点）
            result.push_back(path);
            return;
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        for (int i = startIndex; i < s.size(); i++) {
            // 若截取的是回文串，递归剩下的子串
            if (isPalindrome(s, startIndex, i)) {
                // 处理节点，记录路径
                path.push_back(s.substr(startIndex, i + 1 - startIndex));
                
                backtracking(s, i + 1);     // 递归：控制树的纵向遍历，
                                            //     注意下一层搜索要从i+1开始
                path.pop_back();            // 回溯，撤销处理的节点
            }
        }
    }

    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backtracking(s, 0);
        return result;
    }
};

int main() {
    Solution s;

    string str = "aab";
    
    vector<vector<string>> result = s.partition(str);

    for (vector<string> v : result) {
        for (string s : v) {
            cout << s << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}