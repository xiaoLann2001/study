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

int main() {
    // 输入并初始化
    int s, t, v;
    cin >> n >> m;
    grid.resize(n + 1);
    visited.resize(n + 1, false);
    minDist.resize(n + 1, 1000001); // -100 <= v <= 100, 1 <= m <= 10000
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[s].push_back(Edge(t, v));
    }

    // 初始化visited数组，minDist数组
    minDist[1] = 0; // 起点到自身距离为0

    // 将起点加入队列
    que.push(1);
    visited[1] = true;  // 标记在队列

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
            }
        }
    }

    if (minDist[n] == 1000001) cout << "unconnected" << endl;
    else cout << minDist[n] << endl;

    return 0;
}