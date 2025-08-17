#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 若只有一位数，直接返回本身
        if (n / 10 == 0) return n;
        // 从低位开始依次跟上一位比较是否构成递增
        long long int i = 10; // 记录高位位权
        long long int result = n;
        while (result / i) {
            int high = result / i % 10;
            int low = result / (i / 10) % 10;
            // 若不构成递增，将后面所有低位置9，高位减1
            if (high > low) result = result / i * i - 1;
            i *= 10;
        }
        return (int)result;
    }
};

int main() {
    Solution s;

    int n = 332;

    int result = s.monotoneIncreasingDigits(n);

    cout << result << endl;

    return 0;
}