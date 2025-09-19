#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;
    string path;
    int left_remain, right_remain;

    void backtracking() {
        if (left_remain == 0 && right_remain == 0) {
            result.push_back(path);
        }

        if (left_remain > 0) {
            path.push_back('(');
            left_remain--;
            backtracking();
            left_remain++;
            path.pop_back();
        }
        
        // 即左括号多于右括号，才能加右括号
        if (left_remain < right_remain) {
            path.push_back(')');
            right_remain--;
            backtracking();
            right_remain++;
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n == 0) return result;
        result.clear();
        path.clear();
        left_remain = n;
        right_remain = n;
        path.push_back('(');
        left_remain--;
        backtracking();
        return result;
    }
};

int main() {
    Solution s;

    int n = 3;

    vector<string> ret = s.generateParenthesis(n);

    for (const auto& str : ret) {
        cout << str << endl;
    }

    return 0;
}