#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int m_from;
    int m_to;
    int m_val;

    Edge(int from, int to, int val): m_from(from), m_to(to), m_val(val) {};
};

int n, m, src, dst, k;
vector<Edge> edges;     // 记录所有边
vector<vector<int>> minDist;    // 记录节点到src的最短距离

int main() {
    // 输入并初始化
    int s, t, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        edges.push_back(Edge(s, t, v));
    }
    cin >> src >> dst >> k;
    minDist.resize(k + 2, vector<int>(n + 1, INT32_MAX));

    // 初始化minDist数组
    minDist[0][src] = 0; // 起点到自身距离为0

    // for (auto n : minDist[0]) cout << n << " ";
    // cout << endl;

    for (int i = 1; i <= k + 1; i++) {  // 松弛 k + 1 次
        for (Edge edge : edges) {   // 更新所有边
            if (minDist[i - 1][edge.m_from] != INT32_MAX) {
                if (minDist[i - 1][edge.m_from] + edge.m_val < minDist[i][edge.m_to]) {
                    minDist[i][edge.m_to] = minDist[i - 1][edge.m_from] + edge.m_val;
                }
            }
            minDist[i][edge.m_from] = min(minDist[i][edge.m_from], minDist[i - 1][edge.m_from]);
        }
        // for (auto n : minDist[i]) cout << n << " ";
        // cout << endl;
    }

    if (minDist[k + 1][dst] == INT32_MAX) cout << "unreachable" << endl;
    else cout << minDist[k + 1][dst] << endl;

    return 0;
}