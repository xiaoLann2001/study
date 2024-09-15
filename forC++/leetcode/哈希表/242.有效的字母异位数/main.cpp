// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否
// 是 s 的字母异位词。

// 示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

// 示例 2: 输入: s = "rat", t = "car" 输出: false

// 说明: 你可以假设字符串只包含小写字母

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 首先,字母异位数字母数相等
        if (s.length() != t.length()){
            return false;
        }
        // 其次,字母异位数中,每种字母出现的频数相等
        // 用哈希表记录字母出现的频数,
        // 字母是连续的,作key值用数组即可
        int Alpha_s[26] = {0};
        // 以s为参考,每有一个字母将哈希表对于key的值加1
        // 在t中则减一,若两者频数相等,最后哈希表全为0
        for (int i = 0; i < s.length(); i++){
            Alpha_s[s[i] - 'a']++;
            Alpha_s[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (Alpha_s[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;

    string src("anagram");
    string dst("nagaram");

    if (s.isAnagram(src, dst)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}