#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 若存在重复的子串，则s+s中一定存在s
        string ss = s + s;
        cout << s << " " << ss << " " << endl;

        // 查找ss中是否存在子串s(KMP算法)
        vector<int> next = getNext(s);

        for (int i = 0; i < next.size(); i++)
            cout << next[i] << " ";
        cout << endl;

        // KMP去掉ss前后各一个元素
        int j = 0;
        for (int i = 1; i < ss.length() - 1; i++) {
            while (j > 0 && ss[i] != s[j]) j = next[j - 1];

            if (ss[i] == s[j]) j++; 

            if (j == s.size()) return true;
        }

        return false;
    }

    vector<int> getNext(string s) {
        vector<int> next(s.length());

        cout << "s.length() = " << s.length() << endl;

        // 初始化next表
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < next.size(); i++) {
            // 若s[i]不等于s[j]，则j回退
            while (j > 0 && s[i] != s[j]) j = next[j - 1];

            // 若s[i]等于s[j]，j++
            if (s[i] == s[j]) j++;

            // 更新next表
            next[i] = j;
        }
        return next;
    }
};

class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        // 若存在重复的子串，则s的最大相等前后缀不包含的
        // 子串一定是s的最小重复子串
        
        // 充分条件：如果字符串s是由重复子串组成，那么
        // 最长相等前后缀不包含的子串一定s的最小重复子串。
        // 必要条件：如果字符串s的最长相等前后缀不包含的
        // 子串是s最小重复子串，那么s是由重复子串组成。
        
        // 当最长相等前后缀不包含的子串的长度可以被
        // 字符串s的长度整除，那么不包含的子串 
        // 就是s的最小重复子串。

        // 字符串长度
        int len = s.size();
        if (len == 0) return false;

        // next[len - i]: s的0~(len - i)子串的最大相等前后缀长度
        vector<int> next = getNext(s);

        for (int i = 0; i < next.size(); i++)
            cout << next[i] << " ";
        cout << endl;

        // s的最长相等前后缀长度
        int max = next[len - 1];

        // 当最长相等前后缀不包含的子串的长度可以被
        // 字符串s的长度整除，那么不包含的子串 
        // 就是s的最小重复子串。
        if (max != 0 && len % (len - max) == 0) {
            return true;
        }

        return false;
    }

    vector<int> getNext(string s) {
        vector<int> next(s.length());

        cout << "s.length() = " << s.length() << endl;

        // 初始化next表
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < next.size(); i++) {
            // 若s[i]不等于s[j]，则j回退
            while (j > 0 && s[i] != s[j]) j = next[j - 1];

            // 若s[i]等于s[j]，j++
            if (s[i] == s[j]) j++;

            // 更新next表
            next[i] = j;
        }
        return next;
    }
};

int main() {
    Solution1 s;

    string str = "aabaabaab";

    if (s.repeatedSubstringPattern(str)) 
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}