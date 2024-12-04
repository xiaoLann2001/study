#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> father;

void init() {
    for (int i = 0; i < father.size(); i++) {
        father[i] = i;  // 初始化为根
    }
}

int find(int u) {
    if (u == father[u]) return u;   // 找到根
    else return father[u] = find(father[u]);    // 继续寻根，路径压缩
}

void join(int u, int v) {
    u = find(u);    // 寻找 u 的根
    v = find(v);    // 寻找 v 的根
    if (u == v) return; // u v 的根为同一个，不用连通
    father[v] = u;  // 将 v 的根指向 u 的根
}

bool isSame(int u, int v) {
    u = find(u);    // 寻找 u 的根
    v = find(v);    // 寻找 v 的根
    return u == v;
}

int main() {
    // 输入并初始化
    cin >> n >> m;
    father.resize(n + 1);   // n + 1 是为了对应节点编号
    init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    int s, d;
    cin >> s >> d;

    // 查询
    if (isSame(s, d)) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}