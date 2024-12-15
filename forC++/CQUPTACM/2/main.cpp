#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    int result = 0, count = 0, last_mid = -4; // 初始化为不可能的索引
    unordered_set<char> used_chars;          // 用于记录当前区间已使用的字符

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1] && s[i] == s[i + 1]) { // 滑动窗口取连续相同的三个字符
            if (last_mid != i - 3) { // 当前区间不与上一个区间相邻
                count = 1;           // 重置计数
                used_chars.clear();  // 清空已使用字符集
                used_chars.insert(s[i]);
            } else { // 当前区间与上一个区间相邻
                if (used_chars.find(s[i]) == used_chars.end()) {
                    count++;               // 累积挑战次数
                    used_chars.insert(s[i]); // 记录新字符
                } else { // 如果字符重复，重新开始统计
                    count = max(1, count);
                    used_chars.clear();
                    used_chars.insert(s[i]);
                }
            }
            result = max(result, count); // 更新最大结果
            last_mid = i;                // 更新上一个中间字符的位置
        }
    }

    cout << result << endl;
    return 0;
}
