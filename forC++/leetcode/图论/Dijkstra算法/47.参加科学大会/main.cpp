// #include <bits/stdc++.h>

// using namespace std;

// int n, m;
// map<int, vector<pair<int, int>>> umap;  // 邻接表
// vector<bool> visited;   // 已访问集合
// vector<int> dp; // dp数组，表示minDist

// int main() {
//     // 输入并初始化
//     int s, e, v;
//     cin >> n >> m;
//     visited.resize(n + 1, false);
//     dp.resize(n + 1, INT32_MAX);
//     while (m--) {
//         cin >> s >> e >> v;
//         umap[s].push_back(pair<int, int>{e, v});
//     }

//     // 将起点加入队列
//     dp[1] = 0;
//     queue<int> que;
//     que.push(1);

//     // 迭代求解
//     while (!que.empty()) {
//         // 队首节点：距离起点最近的未访问节点
//         int cur = que.front();
//         que.pop();
//         // 将当前节点加入已访问集合，并更新与它相邻的节点dp值
//         visited[cur] = true;
//         for (pair<int, int> near : umap[cur]) {
//             if (!visited[near.first]) dp[near.first] = min(dp[near.first], dp[cur] + near.second);
//         }
//         // 选择距离起点最近的未访问节点加入队列
//         int next = -1;
//         int minDist = INT32_MAX;
//         for (int i = 1; i <= n; i++) {
//             if (!visited[i] && dp[i] < minDist) {
//                 next = i;
//                 minDist = dp[i];
//             }
//         }
//         if (next != -1) que.push(next);
//     }
    
//     if (dp[n] == INT32_MAX) cout << -1 << endl;
//     else cout << dp[n] << endl;

//     return 0;
// }

// 标准思路
#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int, vector<pair<int, int>>> umap;  // 邻接表
vector<bool> visited;   // 已访问集合
vector<int> minDist;    // 节点距离起点的最短距离

int main() {
    // 输入并初始化
    int s, e, v;
    cin >> n >> m;
    minDist.resize(n + 1, INT32_MAX);
    visited.resize(n + 1, false);
    while (m--) {
        cin >> s >> e >> v;
        umap[s].push_back(pair<int, int>{e, v});
    }

    // 初始化
    minDist[1] = 0;

    // 迭代求解
    for (int i = 1; i < n; i++) {
        // 选择距离起点最近的未访问节点加入队列
        int cur = -1;
        int minTemp = INT32_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minDist[j] < minTemp) {
                cur = j;
                minTemp = minDist[j];
            }
        }
        // 将当前节点加入已访问集合，并更新与它相邻的节点dp值
        if (cur != -1) visited[cur] = true;
        for (pair<int, int> near : umap[cur]) {
            if (!visited[near.first]) minDist[near.first] = min(minDist[near.first], minDist[cur] + near.second);
        }
    }
    
    if (minDist[n] == INT32_MAX) cout << -1 << endl;
    else cout << minDist[n] << endl;

    return 0;
}