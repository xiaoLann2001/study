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
    int cutRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int result = 1;
        // 如果余数是 2，最后乘 2
        if (n % 3 == 2) {
            int numof3 = n / 3;
            while (numof3--) {
                result *= 3;
            }
            result *= 2;
        }
        // 如果余数是 1，要合并一个 3 为 1+3=4 
        else if (n % 3 == 1) {
            int numof3 = n / 3;
            numof3--;
            while (numof3--) {
                result *= 3;
            }
			result *= 4;
        } 
        // 完全能被 3 整除
        else {
            int numof3 = n / 3;
            while (numof3--) {
                result *= 3;
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    int n = 8;

    int ret = s.cutRope(n);

    cout << ret << endl;

    return 0;
}