// 超时
/*
#include <bits/stdc++.h>

using namespace std;

int v, e;   // v: 顶点数, e: 边数
vector<vector<int>> g;  // 邻接矩阵
vector<int> visited;    // 已访问节点

int main() {
    // 输入并初始化
    int v1, v2, val, min_k, min_edge, result;
    cin >> v >> e;
    g.resize(v + 1, vector<int>(v + 1, 0));
    visited.resize(v + 1, 0);
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> val;
        g[v1][v2] = g[v2][v1] = val;
    }

    result = 0;
    visited[1] = 1; // 先将任意一个节点加入已访问集合
    for (int i = 0; i < v - 1; i++) {   // 再取 v - 1 个端，即可构成最小生成树
        min_k = 0;
        min_edge = INT32_MAX;
        for (int j = 1; j <= v; j++) {
            if (visited[j] == 0) continue;      // 保证 j 为已访问集合中的点
            for (int k = 1; k <= v; k++) {
                if (visited[k] == 1) continue;  // 保证 k 为已访问集合之外的点
                if (g[j][k] > 0 && g[j][k] < min_edge) {
                    min_k = k;           // 记录最小边的另一端
                    min_edge = g[j][k];  // 记录最小边权
                }
            }
        }
        visited[min_k] = 1; // 将最小边的另一端标记已访问
        if (min_edge != INT32_MAX) result += min_edge; // 记录总距离
    }

    cout << result << endl;

    return 0;
}
*/

// 官方思路
#include <bits/stdc++.h>

using namespace std;

int v, e;   // 节点数，边数
vector<vector<int>> g;  // 邻接矩阵
vector<bool> isInTree;   // 用于记录已经加入生成树的节点
vector<int> minDist;    // 用于记录每个节点到生成树的最短距离

int main() {
    // 输入并初始化
    int v1, v2, val;
    cin >> v >> e;
    g.resize(v + 1, vector<int>(v + 1, INT32_MAX)); // 邻接矩阵用无穷表示未连接
    isInTree.resize(v + 1, false);
    minDist.resize(v + 1, INT32_MAX);
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> val;
        g[v1][v2] = g[v2][v1] = val;    // 无向图
    }

    isInTree[1] = true; // 任选一个节点加入生成树
    for (int i = 1; i <= v; i++) {  // 更新非生成节点到生成树的距离
        if (g[i][1] > 0 && g[i][1] < minDist[i]) {
            minDist[i] = g[i][1];
        }
    }

    for (int i = 1; i < v; i++) {   // 再加入 v - 1 个节点可构成生成树
        // 一、选择距离生成树最近的节点
        int cur = 0;    // 待选择的节点
        int minTemp = INT32_MAX;
        for (int j = 1; j <= v; j++) {
            // 选择非生成树节点中距离生成树最小的节点，记录节点和最小距离
            if (!isInTree[j] && minDist[j] < minTemp) {
                cur = j;
                minTemp = minDist[j];
            }
        }

        // 二、最近节点加入生成树
        isInTree[cur] = true;

        // 三、更新非生成树节点到生成树的距离
        for (int j = 1; j <= v; j++) {
            // 选择非生成树节点到新加入生成树的节点的边，更新最小距离，与其他生成树节点的距离不变
            if (!isInTree[j] && g[j][cur] < minDist[j]) {
                minDist[j] = g[j][cur];
            }
        }
    }

    // 求最小生成树总距离
    int result = 0;
    for (int i = 2; i <= v; i++) result += minDist[i];
    cout << result << endl;

    return 0;
}