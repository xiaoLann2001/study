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