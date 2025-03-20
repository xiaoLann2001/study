#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        double result = 1.0;
        int flag = false;

        if (exponent < 0) {
            exponent *= -1;
            flag = true;
        }

        while (exponent > 0) {
            if (exponent & 1) {
                result *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return flag ? 1.0 / result : result;
    }
};

class Solution1 {
public:
    double Power(double base, int exponent) {
        double result = 1.0;
        int flag = false;

        if (exponent < 0) {
            exponent *= -1;
            flag = true;
        }

        while (exponent > 0) {
            result *= base;
            exponent--;
        }
        return flag ? 1.0 / result : result;
    }
};

int main() {
    Solution1 s;

    double base = 2.10000;
    int exp = -3;

    double ret = s.Power(base, exp);

    cout << ret << endl;

    return 0;
}