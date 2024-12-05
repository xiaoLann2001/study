#include <bits/stdc++.h>

using namespace std;

int v, e;   // 节点数，边数
multimap<int, vector<int>> edges;    // 以 边权val 为 key 值，对加入的边进行排序
vector<int> father;      // 并查集

void init() {
    for (int i = 1; i <= v; i++) {
        father[i] = i;  // 默认为根
    }
}

int find(int u) {
    return father[u] == u ? u : father[u] = find(father[u]);    // 递归搜索，路径压缩
}

bool isSame(int u, int v) {
    u = find(u);    // 查询 u 的根
    v = find(v);    // 查询 v 的根
    return u == v;
}

void join(int u, int v) {
    u = find(u);    // 查询 u 的根
    v = find(v);    // 查询 v 的根
    if (u == v) return; // u v 已经在同一集合内
    father[v] = u; // 将 v 的根连接到 u 的根 
}

int main() {
    // 输入并初始化
    int v1, v2, val;
    cin >> v >> e;
    father.resize(v + 1);
    init();
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> val;
        edges.insert({val, {v1, v2}});  // 红黑树自动排序
    }

    // 顺序选边，为了保证加入的边构成生成树，需要用并查集检查是否成环
    int result = 0;
    int i = 0;
    for (auto edge : edges) {   // 红黑树自动从小到大遍历
        // cout << "val: \t" << edge.first << "\t" << edge.second[0] << " -> " << edge.second[1] << endl;
        if (i == v - 1) break;      // 选够 v - 1 条边（0 -> v - 2）后，退出循环
        val = edge.first;
        v1 = edge.second[0];
        v2 = edge.second[1];
        if (!isSame(v1, v2)) {  // 若不构成环，将边加入并查集
            join(v1, v2);
            result += val;
            i++;
        }
    }

    cout << result << endl;
    
    return 0;
}