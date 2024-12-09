#### （卡码网）95.城市间货物运输II

思路：
- 1.为了检测负权回路，需要从 **图中有负权回路和没有负权回路的区别** 入手；
- 没有负权回路时：
    - Bellman-ford算法进行 n - 1 次松弛后，minDist结果就不会再改变了；
    - SPFA算法每个节点最多进入 n - 1 次队列，因为入度最多为 n - 1，所以循环会在节点进入 n 次前退出；
- 有负权回路时：
    - Bellman-ford算法在进行 n - 1 次松弛后，再继续松弛，minDist结果会更小，因为负权回路每走一次总代价会减少，这样永远得不到最小值；
    - SPFA算法在处理完所有节点后，还会有负权回路的节点在队列中，反复入队和出队，会有节点入队次数超过 n - 1，因为负权回路每走一次总代价会减少，这样永远得不到最小值；
- 所以要想检测负权回路：
    - 在Bellman-ford算法进行 n - 1 次松弛后，再继续松弛 1 次，如果minDist数组有变，则存在负权回路；
    - 在SPFA算法中添加对节点入队次数的检测，若超过 n - 1，则存在负权回路；

分析：
- 在Bellman-ford算法基础上多松弛一次，因为知道 若没有负权回路n - 1次就能得到结果，所以第 n 次就能得到结果；
- 而SPFA添加对节点入队次数的检测，对于稀疏图可能会有很大的浪费，因为遍历完一边时负权回路的入队次数还远远小于n - 1；


代码：
```c++
// Bellman-ford算法判断负权回路
#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int m_from;
    int m_to;
    int m_val;

    Edge(int from, int to, int val): m_from(from), m_to(to), m_val(val) {};
};

int n, m;
vector<Edge> edges;     // 记录所有边
vector<int> minDist;    // 记录节点到起点的最短距离

int main() {
    // 输入并初始化
    int s, t, v;
    cin >> n >> m;
    minDist.resize(n + 1, INT32_MAX);
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        edges.push_back(Edge(s, t, v));
    }

    // 初始化minDist数组
    minDist[1] = 0; // 起点到自身距离为0
    bool flag = false;  // 默认没有负权回路

    for (int i = 1; i <= n; i++) {  // 松弛 n 次，若有负权回路 minDist会改变
        for (Edge edge : edges) {   // 更新所有边
            if (minDist[edge.m_from] != INT32_MAX) {
                if (minDist[edge.m_from] + edge.m_val < minDist[edge.m_to]) {
                    if (i < n) minDist[edge.m_to] = minDist[edge.m_from] + edge.m_val;
                    else flag = true;   // 若第 n 次松弛仍有minDist更新，存在负权回路
                }
            }
        }
    }

    if (flag) cout << "circle" << endl;
    else if (minDist[n] == INT32_MAX) cout << "unconnected" << endl;
    else cout << minDist[n] << endl;

    return 0;
}
```

```c++
// SPFA算法判断负权回路
#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int m_to;
    int m_val;

    Edge(int to, int val): m_to(to), m_val(val) {};
};

int n, m;
vector<list<Edge>> grid;    // 邻接表
queue<int> que;             // 记录上次松弛的时候更新过的节点
vector<bool> visited;       // 记录在队列中的节点
vector<int> minDist;        // 记录节点到起点的最短距离
vector<int> push_times;     // 记录入队次数

int main() {
    // 输入并初始化
    int s, t, v;
    cin >> n >> m;
    grid.resize(n + 1);
    visited.resize(n + 1, false);
    minDist.resize(n + 1, 1000001); // -100 <= v <= 100, 1 <= m <= 10000
    push_times.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[s].push_back(Edge(t, v));
    }

    // 初始化visited数组，minDist数组
    minDist[1] = 0; // 起点到自身距离为0

    // 将起点加入队列
    que.push(1);
    visited[1] = true;  // 标记在队列
    bool flag = false;  // 默认没有负权回路

    while (!que.empty()) {
        // 取出待松弛的边的出发节点
        int cur = que.front();
        que.pop();
        visited[cur] = false;   // 取出后取消标记
        for (Edge edge : grid[cur]) {
            minDist[edge.m_to] = min(minDist[edge.m_to], minDist[cur] + edge.m_val);
            if (!visited[edge.m_to]) {  // 另一端不在队列中时，松弛
                que.push(edge.m_to);    // 加入队列
                visited[edge.m_to] = true;  // 标记在队列
                push_times[edge.m_to]++;    // 记录入队次数
                if (push_times[edge.m_to] >= n) {   // 入队次数超过 n - 1 次，说明有负权回路
                    flag = true;
                    while (!que.empty()) que.pop();
                    break;
                }
            }
        }
    }

    if (flag) cout << "circle" << endl;
    else if (minDist[n] == 1000001) cout << "unconnected" << endl;
    else cout << minDist[n] << endl;

    return 0;
}
```