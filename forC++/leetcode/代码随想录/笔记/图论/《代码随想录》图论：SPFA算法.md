#### （卡码网）94.城市间货物运输I

思路：
- 1.Bellman-ford算法在每次松弛时对所有边都进行了松弛检查，实际上**真正有效的松弛，是基于已经计算过的节点在做的松弛**。
- 2.所以 Bellman_ford 算法 每次都是对所有边进行松弛，其实是多做了一些无用功。只需要对 **上一次松弛的时候更新过的节点作为出发节点所连接的边** 进行松弛就够了。
- 3.用队列来记录 **上次松弛的时候更新过的节点**。
- 4.在加入队列的过程可以有一个优化，用visited数组记录已经在队列里的元素，已经在队列的元素不用重复加入。

分析：
- 思路1：
    - 基于队列优化的算法，要比Bellman-ford 算法 减少很多无用的松弛情况，特别是对于边数众多的大图 优化效果明显。
    - 如果图越稠密，则 SPFA的效率越接近与 Bellman-ford，反之，图越稀疏，SPFA的效率就越高。
    - 出队列和入队列 其实也是十分耗时的。SPFA（队列优化版Bellman-ford） 在理论上 时间复杂度更胜一筹，但实际上，也要看图的稠密程度，如果 图很大且非常稠密的情况下，虽然 SPFA的时间复杂度接近Bellman-ford，但实际时间消耗 可能是 SPFA耗时更多。
    - while (!que.empty) 会死循环吗？不会，因为图中没有负权回路，正权回路也不会影响最小值。

遇到的问题：
```c++
    // 将起点加入队列
    que.push(1);
    visited[1] = true;  // 标记在队列

    while (!que.empty()) {
        // 取出待松弛的边的出发节点
        int cur = que.front();
        que.pop();
        visited[cur] = false;   // 取出后取消标记
        for (Edge edge : grid[cur]) {
            if (!visited[edge.m_to]) {  // 另一端不在队列中时，松弛
                minDist[edge.m_to] = min(minDist[edge.m_to], minDist[cur] + edge.m_val);
                que.push(edge.m_to);    // 加入队列
                visited[edge.m_to] = true;  // 标记在队列
            }
        }
    }
```
- 以上代码中，minDist只有在被指向的节点不在队列中，才会更新，看似符合直觉：因为是一层一层选择边的出发点进行松弛的；
- 但是，“队列中的元素” 不一定是同一层，除非图是树形结构，所以，即使边的两个节点都在队列中，也可能属于最短路径的不同层的节点，也要进行minDist的更新，防止错过更优的情况；
- 检查是否在队列只是为了防止重复添加同一节点到队列，让每一轮松弛选择的节点内部不重复（不同轮的松弛是可能包含同一个节点的）；
- 综上，应该把minDist更新的代码，放到检查是否在队列分支的外部；

代码：
```c++
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
```