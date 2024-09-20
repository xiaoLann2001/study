// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，

// 就反转这 2k 字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。

// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

#include <iostream>
#include <string>

#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // 若待处理的字符串长度>=k，则分段反转，记录位置反转区间[2ki, k(2i+1)-1)
        // 若待处理的字符串长度<k，则全部反转，记录位置反转区间[2ki, n-1)
        // i记录第几段，n为字符串长度
        // 用于反转的指针left, right

        int left, right, i, n;
        i = 0;
        n = s.length();

        while (n - (2 * i * k) >= k) {  // 直接用(s.length()-2ik)会出bug
            left = 2 * i * k;
            right = left + k - 1;

            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            i++;
        }
        // 反转剩余不足k个的字符
        left = 2 * i * k;
        right = s.length() - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }      

        return s;
    }
};

class Solution1 {
public:
    string reverseStr(string s, int k) {
        // 若待处理的字符串长度>=k，则分段反转，记录位置反转区间[2ki, k(2i+1)-1)
        // 若待处理的字符串长度<k，则全部反转，记录位置反转区间[2ki, n-1)
        // i记录第几段，n为字符串长度
        // 用于反转的指针left, right

        int left, right, i, n;
        i = 0;
        n = s.length();

        while (n - (2 * i * k) > 0) {  // 直接用(s.length()-2ik)会出bug
            left = 2 * i * k;
            // right = left + k - 1;
            // 改进：将不足k和>=k的情况合并
            right = min(left + k - 1, n - 1);

            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            i++;
        }     

        return s;
    }
};

// 使用库函数
class Solution2 {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main() {
    Solution1 s;

    string str = "abcdefg";
    string result;
    int k = 2;

    result = s.reverseStr(str, k);

    cout << result << endl;

    return 0;
}