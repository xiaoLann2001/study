#include <bits/stdc++.h>

using namespace std;

// 集合去重
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串vector
     */
    vector<string> Permutation(string str) {
        result_set.clear();
        if (str.empty()) {
            return vector<string>();
        }

        Permutation(str, 0);

        return vector<string>(result_set.begin(), result_set.end());
    }

    void Permutation(string str, int begin) {
        if (begin == str.size() - 1) {
            result_set.insert(str);
        }

        for (int i = begin; i < str.size(); i++) {
            swap(str[begin], str[i]);
            Permutation(str, begin + 1);
            swap(str[begin], str[i]);   // 回溯
        }
    }

    set<string> result_set; // 集合去重
};

// 去重逻辑：先排序，每一层（每一个位置上）不出现重复的元素，对本层去重
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串vector
     */
    vector<string> Permutation(string str) {
        path.clear();
        result.clear();
        if (str.empty()) {
            return vector<string>();
        }
        
        vector<int> used;      // 记录已使用元素的索引
        used.resize(str.size(), 0);
        sort(str.begin(), str.end());
        Permutation(str, used);

        return result;
    }

    void Permutation(string str, vector<int>& used) {
        if (path.size() == str.size()) {
            result.push_back(path);
        }

        for (int i = 0; i < str.size(); i++) {
            if (i > 0 && str[i] == str[i - 1] && used[i - 1] == 0) continue;  // 去重
            // if (i > 0 && str[i] == str[i - 1] && used[i - 1] == 1) continue;  // 去重，对树层中前一位去重，就用used[i - 1] == false，
                                                                                // 如果要对树枝前一位去重用used[i - 1] == true
            if (used[i] == 0) {
                used[i] = 1;
                path.push_back(str[i]);
                Permutation(str, used);
                path.pop_back();    // 回溯
                used[i] = 0;
            }
        }
    }

    string path;
    vector<string> result;
};

int main() {
    Solution s;

    string str = "aaba";

    vector<string> ret = s.Permutation(str);

    for (auto _str : ret) {
        cout << _str << endl;
    }

    return 0;
}