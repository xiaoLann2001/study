#include <iostream>
#include <vector>

using namespace std;

// 假设有 100 个元素
const int n = 100;

// 并查集
vector<int> father(n);

// 初始化
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

// 查询
int find(int x) {
    if (father[x] == x) {
        return x;
    } else {
        father[x] = find(father[x]);    // 路径压缩
        return father[x];
    }
}

// 合并 u -> v
void merge(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        father[root_u] = root_v;
    }
}

// 判断 u, v是否连通
bool is_connected(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    return root_u == root_v;
}

int main() {
    init();
    merge(1, 2);
    merge(2, 3);
    merge(1, 4);
    merge(5, 6);
    merge(6, 7);

    cout << is_connected(2, 4) << endl;
    cout << is_connected(5, 1) << endl;
    cout << is_connected(5, 7) << endl;

    return 0;
}