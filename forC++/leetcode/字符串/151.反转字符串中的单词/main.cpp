// 给你一个字符串 s ，请你反转字符串中 单词 的顺序。

// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。

// 返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 1.反转用一个或多个空格隔开的单词，单词内顺序不变
        // 2.消除前导空格和尾随空格
        // 3.结果中的单词只用一个空格隔开

        // 一、先整体反转,reverse()

        // 二、使用双指针法，分别反转每一个单词：
        // 遍历旧指针：
        // 1.跳过连续的空格；
        // 2.遇到末尾时，跳出循环；
        // 3.当旧指针遇到字母时，记录新指针的值为单词起始位置，将字母从旧指针拷贝到
        // 新指针，新旧指针同时右移；
        // 4.当旧指针遇到空格或末尾时，反转单词，置标置位为1，表示新数组前有单词；
        // 5.遍历结束，移除末尾多余字符。

        reverse(s.begin(), s.end());

        int p_old = 0, p_new = 0, n = s.length(), start = 0, f_word = 0;

        while (p_old < n) {
            // 消除前置空格
            while (p_old < n && s[p_old] == ' ') p_old++;
            if (p_old >= n) break;

            // 在新数组单词间加上空格
            if (f_word) s[p_new++] = ' ';

            // 遍历旧数组单词，记录单词数量
            start = p_new;
            while (p_old < n && s[p_old] != ' ') {
                s[p_new++] = s[p_old++];
            }
            // 反转单词
            reverse(s.begin() + start, s.begin() + p_new);
            f_word = 1;
        }

        // 删除多余的尾部字符
        s.erase(s.begin() + p_new, s.end());

        return s;
    }
};

int main() {
    Solution s;

    string str = " the sky is blue  ";
    string r;

    r = s.reverseWords(str);

    cout << r << endl;

    return 0;
}