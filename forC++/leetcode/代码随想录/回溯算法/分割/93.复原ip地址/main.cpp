#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> path;                   // 路径
    vector<string> result;              // 结果
    int count = 0;

    // 判断是不是有效ip段，参数字符串，起始位置，结束位置，左闭右闭
    bool isValidIpSeg(const string &s, int start, int end) {
        if (end - start + 1 > 3) return false;
        else if (end - start + 1 > 1 && s[start] == '0') return false;
        int num = 0;
        while (start <= end) {
            if (s[start] < '0' || s[start] > '9') return false;
            num *= 10;
            num += s[start] - '0';
            start++;
        }
        if (num > 255) return false;
        return true;
    }

    void backtracking(const string &s, int startIndex) {
        count++;
        if (path.size() >= 4) {
            if ( path.back() == s.size()) {
                // 到达叶子，将路径中前三个截取点，从右往左插入到字符串中
                string temp = s;
                int idx = 2;
                while (idx >= 0) {
                    temp.insert(path[idx], 1, '.');
                    idx--;
                }
                result.push_back(temp);
                return;
            } else {
                return;     // 不符合条件，返回
            }
        }

        // 回溯法的搜索过程就是一个树型结构的遍历过程，
        // for循环用来横向遍历，递归的过程是纵向遍历。
        for (int i = startIndex; i < s.size() && i - startIndex + 1 <= 3; i++) {
            // 对长度剪枝
            if (s.size() - i < 4 - path.size()) break;
            if (s.size() - i > 3 * (4 - path.size())) continue;

            // 若截取的是有效ip段，记录截取点，递归剩下的子串
            if (isValidIpSeg(s, startIndex, i)) {
                // 处理节点，记录路径
                path.push_back(i + 1);
                
                backtracking(s, i + 1);     // 递归：控制树的纵向遍历，
                                            //     注意下一层搜索要从i+1开始
                path.pop_back();            // 回溯，撤销处理的节点
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        path.clear();
        result.clear();
        backtracking(s, 0);
        cout << "递归次数" << count << endl;
        return result;
    }
};

int main() {
    Solution s;

    string str = "25525511135";
    
    vector<string> result = s.restoreIpAddresses(str);

    for (string s : result) {
        std::cout << s << ", ";
    }
    std::cout << endl;

    return 0;
}