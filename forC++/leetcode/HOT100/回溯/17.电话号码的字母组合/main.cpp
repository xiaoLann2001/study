#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, string> digit2string;
    vector<string> result;
    string path;

    void backtracking(string digits, int level) {
        if (path.size() == digits.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < digit2string[digits[level]].size(); i++) {
            path.push_back(digit2string[digits[level]][i]);
            backtracking(digits, level + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;

        digit2string['2'] = "abc";
        digit2string['3'] = "def";
        digit2string['4'] = "ghi";
        digit2string['5'] = "jkl";
        digit2string['6'] = "mno";
        digit2string['7'] = "pqrs";
        digit2string['8'] = "tuv";
        digit2string['9'] = "wxyz";

        backtracking(digits, 0);
        return result;
    }
};

int main() {
    Solution s;

    string input = "22";

    vector<string> ret = s.letterCombinations(input);

    for (const auto& str : ret) {
        cout << str << endl;
    }

    return 0;
}