#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    unsigned long long k, seg, offset;
    cin >> n;
    vector<int> table(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }
    cin >> q;
    while (q--) {
        cin >> k;
        int cnt = 0;
        seg = (k - 1) / n;
        offset = (k - 1) % n;
        // 求二进制形式 seg 的 1 的个数
        while (seg) {
            cnt += seg & 1;
            seg >>= 1;
        }
        if (cnt % 2 == 0) {
            cout << table[offset] << endl;
        } else {
            cout << (char)(table[offset] + 'a' - 1) << endl;
        }
    }
    return 0;
}
