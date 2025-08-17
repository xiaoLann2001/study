#### （卡码网）47.参加科学大会

思路：
- 1.在 朴素Dijkstra 流程中，处理**稀疏图**时，若**按照端**来更新minDist数组，每次循环第一步需要**遍历所有端**来寻找**距离起点最近的未访问节点**，存在较大的时间浪费，邻接矩阵也会存在较大的空间浪费；
- 2.所以可以考虑在处理稀疏图时**按照边**来更新minDist数组，考虑用**邻接表**来表示图，为了不用每次遍历所有边，使用**小顶堆**来对边自动排序，每次只需要取堆顶元素即可。

分析：
- 思路1 时间复杂度O(ElogE)；

代码：
```c++
// 堆优化Dijkstra
#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
    int m_to;   // 边指向的端
    int m_val;  // 边权

    Edge(int to, int val): m_to(to), m_val(val) {};
};

class Comparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second; // 小顶堆要判断 greater
    }
};

int n, m;
vector<list<Edge>> grid;  // 邻接表
vector<int> minDist;    // 节点距离起点的最短距离
vector<bool> visited;   // 已访问集合
priority_queue<pair<int, int>, vector<pair<int, int>>, Comparison> pq;    // 用于对边排序的堆

int main() {
    // 输入并初始化
    int s, e, v;
    cin >> n >> m;
    grid.resize(n + 1);
    minDist.resize(n + 1, INT32_MAX);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> v;
        grid[s].push_back(Edge(e, v));
    }

    // 先将与起点关联的边加入堆，初始化距离起点最小距离数组
    pq.push(pair<int, int>{1, 0});
    minDist[1] = 0;

    // 迭代求解
    for (int i = 0; i < m; i++) {
        // 取出堆顶元素，其距离顶点最短
        pair<int, int> cur = pq.top();
        pq.pop();
        // 将当前节点标记为已访问
        visited[cur.first] = true;
        // 更新距离起点的最小距离，将与当前节点相邻的边加入堆，自动排序
        for (Edge edge : grid[cur.first]) {
            if (!visited[edge.m_to] && minDist[cur.first] + edge.m_val < minDist[edge.m_to]) {
                minDist[edge.m_to] = minDist[cur.first] + edge.m_val;
                pq.push(pair<int, int>{edge.m_to, minDist[edge.m_to]});
            }
        }
    }
    
    if (minDist[n] == INT32_MAX) cout << -1 << endl;
    else cout << minDist[n] << endl;

    return 0;
}
```