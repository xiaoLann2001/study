// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

// 注意：

// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

// 示例 1：

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// 示例 2：

// 输入：s = "a", t = "a"
// 输出："a"
// 解释：整个字符串 s 是最小覆盖子串。
// 示例 3:

// 输入: s = "a", t = "aa"
// 输出: ""
// 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
// 因此没有符合条件的子字符串，返回空字符串。
 

// 提示：

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s 和 t 由英文字母组成
 

// 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// 双指针法（滑动窗口法）（错误实现）
// "覆盖子串"是指在字符串 s 中找到一个子串，使得这个子串包含了字符串 t 中的所有字符，并且要求覆盖的字符数量和次数满足 t 中字符的要求。
// 出现种类和次数要相等，而不是在s中能找到所有的t
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;

        for (; right < s.size(); ++right) { 
            // 通过判断是否满足覆盖字串的条件来缩小窗口
            while (condition(s.substr(left, right - left), t)) { // 若满足条件，缩小窗口
                ++left;
            }
        }

        return s.substr(left, right - left);
    }

    bool condition(const std::string& s, const std::string& t) {
        std::unordered_map<char, int> charCount; // 用于记录字符串 s 中每个字符的出现次数

        // 统计字符串 s 中每个字符的出现次数
        for (char c : s) {
            charCount[c]++;
        }

        // 检查字符串 t 中的每个字符是否能够在字符串 s 中找到相应次数的匹配
        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return false; // 字符 c 在 s 中不存在或已经用完，无法覆盖 t 中的字符
            }
            charCount[c]--; // 使用掉一个字符 c
        }

        return true; // 字符串 s 能够找到字符串 t 的所有字符
    }
};

// 双指针法（滑动窗口法）
class Solution1 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetCharCount;       // 用哈希表记录t中的各字符出现的次数
        for (char c : t) {
            targetCharCount[c]++;
        }

        int left = 0;
        int minLen = INT32_MAX;
        int formedChars = 0;        // 记录当前覆盖到的字符数
        int minStart = 0;

        unordered_map<char, int> windowCharCount;       // 用哈希表记录当前s窗口内匹配到t中的各个字符出现的次数

        for (int right = 0; right < s.size(); ++right) {
            char currentChar = s[right];                // 访问新的右字符
            // if (targetCharCount.find(currentChar) != targetCharCount.end()) {       // 若该字符能在t中找到
            windowCharCount[currentChar]++;         // 当前s窗口内匹配到t中的该字符出现的次数加1
            if (windowCharCount[currentChar] <= targetCharCount[currentChar]) { // 若s窗口内匹配到t中的该字符出现的次数 小于等于 t中的各字符出现的次数
                formedChars++;                      // （有效字符）覆盖到的字符数加1
            }
            // }

            while (formedChars == targetCharCount.size() && left <= right) {        // 当覆盖到的字符数等于t的字符数 且 窗口存在
                // 去除冗余字符
                // 更新最小覆盖子串的信息
                int currentLen = right - left + 1;      // 当前窗口长度，左闭右闭
                if (currentLen < minLen) {              // 若当前窗口长度比记录的最小窗口小
                    minLen = currentLen;                // 更新最小窗口
                    minStart = left;                    // 记录最小覆盖窗口起始位置
                }

                // 缩小窗口左边界
                char leftChar = s[left];                // 访问新的左字符
                if (targetCharCount.find(leftChar) != targetCharCount.end()) {      // 若该字符能在t中找到，则前面窗口的该字符为冗余字符
                    windowCharCount[leftChar]--;        // 当前s窗口内匹配到t中的该字符出现的次数减1
                    if (windowCharCount[leftChar] < targetCharCount[leftChar]) {    // 若s窗口内匹配到t中的该字符出现的次数 小于 t中的各字符出现的次数
                        formedChars--;                  // 覆盖到的字符数减1
                    }
                }
                left++;                                 // 窗口左指针前进
            }
        }

        if (minLen == INT32_MAX) {
            return ""; // 没有找到覆盖所有字符的子串
        } else {
            return s.substr(minStart, minLen); // 返回最小覆盖子串
        }
    }
};

// 双指针法（滑动窗口法）
class Solution2 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;                            // hs：当前窗口各字符频数， ht：目标字符串各字符频数
        for (int i = 0; i < t.length(); i++) ht[t[i]]++;            // 统计目标各字符频数

        string ans;
        for (int i = 0, j = 0, cnt = 0; i < s.length(); i++) {      // 右指针i遍历整个s字符串
            if (++hs[s[i]] <= ht[s[i]]) cnt++;                      // 若右字符加在s中后的频数 小于等于 在t中的频数，则为有效字符，cnt+1
            while (hs[s[j]] > ht[s[j]]) hs[s[j++]]--;               // 去除冗余左字符，减去左字符在s中的频数
            if (cnt == t.length() || ans.length() > i - j + 1) {    // 当有效字符数满足要求，或窗口长度变短后：更新窗口长度
                ans = s.substr(j, i - j + 1);
            }
        }
        return ans;
    }
};

int main(){
    Solution1 sol;

    string s = "a"; 
    string t = "aa";

    string result = sol.minWindow(s, t);

    cout << result << endl;

    return 0;
}