

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 查找字符串n是否在h中出现
        // 使用双指针法：
        // 1. p_h遍历字符串h，直到末尾
        // 2.1 当h[p_h]==n[p_n]时，用start记录p_h, 然后p_h和p_n同时右移，
        // 判断p_n是否到达n末尾，若到达则返回start
        // 2.2 当h[p_h]！=n[p_n]时，p_n=0, p_h右移。
        // 3. 未找到子串，返回-1
        
        int p_h = 0, p_n = 0, start = 0, 
            l_h = haystack.length(), l_n = needle.length();

        while (p_h < l_h) {
            if (haystack[p_h] != needle[p_n]) {
                p_h++;
                continue;
            }
            start = p_h;
            while (haystack[p_h] == needle[p_n]) {
                if (p_h < l_h) p_h++;
                else break;
                p_n++;
                if (p_n > l_n - 1) return start;
            }
            p_h = start + 1;
            p_n = 0;
        }
        return -1;
    }
};

int main() {
    Solution s;

    string h = "mississippi";
    string n = "issip";

    int ret = s.strStr(h, n);
    cout << ret << endl;

    return 0;
}