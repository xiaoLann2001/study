#include <iostream>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

// 假设有 10 个元素
const int n = 10;

// 并查集
vector<int> father(n + 1);
vector<int> treesize(n + 1);

struct undo_object {    // 记录上一次操作的两个根节点的size（合并的较大的子树的大小）或者father（被合并的较小的子树的原来的根）
    int _pos;
    int _val;
    undo_object() {};
    undo_object(int pos, int val) {
        _pos = pos;
        _val = val;
    };
};

stack<undo_object> undo_father;
stack<undo_object> undo_treesize;

// 初始化
void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        treesize[i] = 1;
    }
    while (!undo_father.empty()) undo_father.pop();
    while (!undo_treesize.empty()) undo_treesize.pop();
}

// 查询
int find(int x) {
    if (father[x] == x) return x;
    return find(father[x]);
}

// 合并 u -> v
void merge(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        // 启发式合并，小的树加入大的树，不能使用路径压缩，否则会破坏树形结构，导致无法撤销
        if (treesize[root_u] > treesize[root_v]) swap(root_u, root_v);

        // 记录上一步操作
        undo_father.push(undo_object(root_u, father[root_u]));
        undo_treesize.push(undo_object(root_v, treesize[root_v]));

        // 合并
        father[root_u] = root_v;
        treesize[root_v] += treesize[root_u];
    }
}

// 判断 u, v是否连通
bool is_connected(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    return root_u == root_v;
}

// 撤销上一步操作
void undo() {
    // 检查是否能撤销
    if (undo_father.empty() || undo_treesize.empty()) return;
    // 撤销回小子树原来的根
    father[undo_father.top()._pos] = undo_father.top()._val;
    undo_father.pop();
    // 撤销回大子树原来的大小
    treesize[undo_treesize.top()._pos] = undo_treesize.top()._val;
    undo_treesize.pop();
}

int main() {
    init();
    merge(1, 2);
    merge(2, 3);
    merge(1, 4);
    undo();
    merge(5, 6);
    merge(6, 7);
    merge(6, 2);
    undo();
    undo();

    for (const auto& n : father) cout << n << " ";
    cout << endl;
    for (const auto& n : treesize) cout << n << " ";
    cout << endl;

    cout << is_connected(2, 4) << endl;
    cout << is_connected(5, 1) << endl;
    cout << is_connected(5, 7) << endl;

    return 0;
}