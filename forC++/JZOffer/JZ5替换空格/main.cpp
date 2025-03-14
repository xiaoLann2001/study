#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // 一个空格替换为"%20"，需要移动原来的空间，如果空格很多，频繁移动比较费时
        int newsize = s.size();

        // 先统计需要拓展的空间
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') newsize += 2;
        }
        
        // 双指针替换
        int p_old = s.size() - 1;
        int p_new = newsize - 1;

        // 扩容
        s.resize(newsize);

        // 再从末尾开始向前替换
        while (p_old >= 0) {
            if (s[p_old] == ' ') {
                s[p_new - 2] = '%';
                s[p_new - 1] = '2';
                s[p_new] = '0';
                p_new -= 3;
            } else {
                s[p_new] = s[p_old];
                p_new--;
            }
            p_old--;
        }
        return s;
    }
};

int main() {
    Solution s;

    string input = "We Are Happy";

    string ret = s.replaceSpace(input);

    cout << ret << endl;

    return 0;
}