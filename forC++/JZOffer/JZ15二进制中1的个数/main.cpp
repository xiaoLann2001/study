#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int NumberOf1(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution s;

    int n = 10;

    int ret = s.NumberOf1(n);

    cout << ret << endl;

    return 0;
}