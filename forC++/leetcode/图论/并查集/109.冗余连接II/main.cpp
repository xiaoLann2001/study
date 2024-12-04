// #include <bits/stdc++.h>

// using namespace std;

// int n;
// vector<int> father;

// void init() {
//     for (int i = 0; i < father.size(); i++) {
//         father[i] = i;  // 初始化为根
//     }
// }

// int find(int u) {
//     if (u == father[u]) return u;   // 找到根
//     else return father[u] = find(father[u]);    // 继续寻根，路径压缩
// }

// void join(int u, int v) {
//     u = find(u);    // 寻找 u 的根
//     v = find(v);    // 寻找 v 的根
//     if (u == v) return; // u v 的根为同一个，不用连通
//     father[v] = u;  // 将 v 的根指向 u 的根
// }

// bool isSame(int u, int v) {
//     u = find(u);    // 寻找 u 的根
//     v = find(v);    // 寻找 v 的根
//     return u == v;
// }

// int main() {
//     // 输入并初始化
//     int s, t, flag = 0, result[2];
//     cin >> n;
//     father.resize(n + 1);   // n + 1 是为了对应节点编号
//     init();
    
//     for (int i = 0; i < n; i++) {
//         cin >> s >> t;
//         if (t != find(t)) flag = 1; // 若 t 已经有父节点了，置标置位，存在非有向环
//         if (flag == 0 && isSame(s, t)) {// 若成有向环，记录结果
//             result[0] = s;
//             result[1] = t;
//         }
//         join(s, t);
//     }

//     // 成有向环，无根节点，输出最后成环的一条边
//     if (flag == 0) cout << result[0] << " " << result[1] << endl;

//     // 非有向环，有根节点，从根节点开始，标记边
    

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> father (1001, 0);
// 并查集初始化
void init() {
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}
// 将v->u 这条边加入并查集
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    father[v] = u;
}
// 判断 u 和 v是否找到同一个根
bool same(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 在有向图里找到删除的那条边，使其变成树
void getRemoveEdge(const vector<vector<int>>& edges) {
    init(); // 初始化并查集
    for (int i = 0; i < n; i++) { // 遍历所有的边
        if (same(edges[i][0], edges[i][1])) { // 构成有向环了，就是要删除的边
            cout << edges[i][0] << " " << edges[i][1];
            return;
        } else {
            join(edges[i][0], edges[i][1]);
        }
    }
}

// 删一条边之后判断是不是树
bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
    init(); // 初始化并查集
    for (int i = 0; i < n; i++) {
        if (i == deleteEdge) continue;
        if (same(edges[i][0], edges[i][1])) { // 构成有向环了，一定不是树
            return false;
        }
        join(edges[i][0], edges[i][1]);
    }
    return true;
}

int main() {
    int s, t;
    vector<vector<int>> edges;
    cin >> n;
    vector<int> inDegree(n + 1, 0); // 记录节点入度
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        inDegree[t]++;
        edges.push_back({s, t});
    }

    vector<int> vec; // 记录入度为2的边（如果有的话就两条边）
    // 找入度为2的节点所对应的边，注意要倒序，因为优先删除最后出现的一条边
    for (int i = n - 1; i >= 0; i--) {
        if (inDegree[edges[i][1]] == 2) {
            vec.push_back(i);
        }
    }
    // 情况一、情况二
    if (vec.size() > 0) {
        // 放在vec里的边已经按照倒叙放的，所以这里就优先删vec[0]这条边
        if (isTreeAfterRemoveEdge(edges, vec[0])) {
            cout << edges[vec[0]][0] << " " << edges[vec[0]][1];
        } else {
            cout << edges[vec[1]][0] << " " << edges[vec[1]][1];
        }
        return 0;
    }

    // 处理情况三
    // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
    getRemoveEdge(edges);
}