#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<list<int>> g;    // 邻接表
vector<int> visited;    // 已访问节点

void dfs(int node_cur) {
    // 处理当前节点
    visited[node_cur] = 1;  // 标记已访问
    // 搜索相邻节点
    for (auto node_next : g[node_cur]) {
        if (visited[node_next] == 0) {
            dfs(node_next);
        }
    }
}

void bfs(int node_start) {
    queue<int> queue_next;
    queue_next.push(node_start);
    visited[node_start] = 1;  // 标记已访问
    while (!queue_next.empty()) {
        // 当前节点
        int node_cur = queue_next.front();
        queue_next.pop();
        // 搜索相邻节点
        for (auto node_next : g[node_cur]) {
            if (visited[node_next] == 0) {
                queue_next.push(node_next);
                visited[node_next] = 1;
            }
        }
    }
}

int main() {
    // 输入并初始化
    cin >> n >> k;
    g.resize(n + 1);    // n + 1 为了对应节点编号
    visited.resize(n + 1, 0);
    int s, t;
    while (k--) {
        cin >> s >> t;
        g[s].push_back(t);
    }

    // 从 节点1 搜索并标记节点
    bfs(1);

    // 检查是否标记完
    int result = 1;
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 0) result = -1;
    }
    cout << result << endl;

    return 0;
} 