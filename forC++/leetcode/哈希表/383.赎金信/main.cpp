// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

#include <iostream>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 将magazine中的字符统计进哈希映射
        // 若ransomNote中的字符能由magazine中的字符表示
        // 则r包含于m,遍历r,每使用一个字符,在哈希映射中减1
        // 若哈希映射没有value<0,则成功

        unordered_map<char, int> alphatable;
        for (char c : magazine) {
            alphatable[c]++;
        }

        for (char c : ransomNote) {
            alphatable[c]--;
            if (alphatable[c] < 0)
                return false;
        }
        return true;
    }
};

class Solution1 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 将magazine中的字符统计进哈希映射
        // 若ransomNote中的字符能由magazine中的字符表示
        // 则r包含于m,遍历r,每使用一个字符,在哈希映射中减1
        // 若哈希映射没有value<0,则成功

        // 改进:用数组
        int alphatable[26];
        for (char c : magazine) {
            alphatable[c - 'a']++;
        }

        for (char c : ransomNote) {
            alphatable[c - 'a']--;
            if (alphatable[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
  

int main()
{
    Solution1 s;

    string r = "aa";
    string m = "aab";

    if (s.canConstruct(r, m)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}