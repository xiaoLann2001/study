#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void backtracking(const string& s, int start) {
        if (start == s.size()) { // 到达末尾，收集结果
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                // 前面分割后，前面的子串就确定了，只需继续分割后面的子串
                path.push_back(s.substr(start, i - start + 1)); // 选择子串
                backtracking(s, i + 1); // 递归到下一段
                path.pop_back(); // 回溯
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};

int main() {
    Solution s;
    string input = "aab";

    auto ret = s.partition(input);

    for (auto& v : ret) {
        for (auto& str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
