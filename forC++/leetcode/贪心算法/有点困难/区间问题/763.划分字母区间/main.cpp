#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    static bool cmp(vector<int> first, vector<int> second) {
        return first[0] < second[0];
    }

    vector<int> partitionLabels(string s) {
        if (s.size() == 1) return vector<int>{1};
        vector<vector<int>> alpha_interval(26, vector<int>(2, INT32_MAX));
        int alpha_num = 0;  // 记录不同字母的数量
        for (int i = 0; i < s.size(); i++) {
            if (alpha_interval[s[i] - 'a'][0] == INT32_MAX) {
                alpha_interval[s[i] - 'a'][0] = i;
                alpha_interval[s[i] - 'a'][1] = i;
                alpha_num++;
            } else {
                alpha_interval[s[i] - 'a'][1] = i;
            }
        }
        // cout << "alpha_num: " << alpha_num << endl;
        sort(alpha_interval.begin(), alpha_interval.end(), cmp);

        int last = 0;
        vector<int> result;
        int right_bound = alpha_interval[0][1];
        for (int i = 1; i < alpha_num; i++) {
            if (alpha_interval[i][0] > right_bound) {
                right_bound = alpha_interval[i][1];
                result.push_back(alpha_interval[i][0] - last);
                last = alpha_interval[i][0];
            } else {
                right_bound = max(right_bound, alpha_interval[i][1]);
            }
        }
        result.push_back(s.size() - last);
        return result;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
            hash[S[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    string str = "ababcbacadefegdehijhklij";

    vector<int> result = s.partitionLabels(str);

    for (const auto n : result) {
        cout << n << ", ";
    }
    cout << endl;

    return 0;
}