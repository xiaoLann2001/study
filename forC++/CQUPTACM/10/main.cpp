#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1.需要满足 3/n = 2/x + 2/y + 1/z
    // 2.由于只需要任求一组结果，所以可以假设 x, y, z 与 n 存在一定的关系
    // 3.假设经过通分后，有 3a/na = 2b/xb + 2c/yc + 1d/zd
    // 4.有 3a = 2b + 2c + d（1），na = xb = yc = zd（2），x != y（3）y != z（4）x != z（5）
    // 5.由（3）（4）（5），可知 b != c != d
    // 6.由 3a = 2b + 2c + d 可知，等式左边一定为 3的倍数
    
    // 处理输入
    int T, n, x, y, z;
    cin >> T;
    while (T--) {
        cin >> n;
        x = 4 * n / 3;
        y = 2 * n;
        z = 2 * n;
        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}