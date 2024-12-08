#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int m_from;
    int m_val;

    Edge(int from, int val): m_from(from), m_val(val) {};
};

int n, m;
vector<list<Edge>> grid;    // 邻接表，索引为被指向元素，list存放的是指向它的元素
vector<bool> visited;
vector<int> minDist;    // 记录节点到起点的最短距离

int main() {
    // 输入并初始化
    int s, t, v;
    cin >> n >> m;
    grid.resize(n + 1);
    visited.resize(n + 1, false);
    minDist.resize(n + 1, 1000001); // -100 <= v <= 100, 1 <= m <= 10000
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grid[t].push_back(Edge(s, v));
    }

    // 初始化visited数组，minDist数组
    visited[1] = true;  // 标记已更新
    minDist[1] = 0; // 起点到自身距离为0

    for (int i = 1; i <= n - 1; i++) {  // 松弛 n - 1 次即可得到最短路径长度
        for (int j = 2; j <= n; j++) {  // 更新剩下 n - 1 个节点
            for (Edge edge : grid[j]) {
                if (visited[edge.m_from]) {
                    visited[j] = true;  // 标记已更新
                    minDist[j] = min(minDist[j], minDist[edge.m_from] + edge.m_val);
                }
            }
        }
    }

    if (minDist[n] == 1000001) cout << "unconnected" << endl;
    else cout << minDist[n] << endl;

    return 0;
}