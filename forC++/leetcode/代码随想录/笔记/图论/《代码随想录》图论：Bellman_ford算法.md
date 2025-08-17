#### （卡码网）94.城市间货物运输I

思路：
- 1.Bellman-Ford 算法的**迭代松弛操作**，实际上就是按顶点距离 s 的层次，**逐层生成**这棵最短路径树的过程。
    - 在对每条边进行第 1 遍松弛的时候，生成了从s出发,层次至多为 1 的那些树枝。也就是说，找到了与s至多有1条边相联的那些顶点的最短路径;
    - 对每条边进行第 2 遍松弛的时候，生成了第 2 层次的树枝，就是说找到了经过 2 条边相连的那些顶点的最短路径......
    - 因为最短路径最多只包含 n-1 条边,所以,只需要循环 n-1 次（ n 为节点数）；
    - 每实施一次松弛操作，**最短路径树上**就会有一层顶点达到其最短距离，此后这层顶点的最短距离值就会一直保持不变，不再受后续松弛操作的影响。
    - 注意：**最短路径树上**的松弛结果不变只是最终结果表现出来的，实际遍历时不知道哪个是最短路径树，还是要去比较每个节点，包括已经访问过的；
- 2.代码随想录官方给出的思路更简单易懂：
    - **Bellman_ford算法的核心思想是 对所有边进行松弛n-1次操作（n为节点数量），从而求得目标最短路。**
    - 所以每次松弛只关注每条边，更新公式里面的信息，边两端的节点和边权都能获取到，所以图只用存{s, t, v}即可；

分析：
- 思路1：
    - 需要松弛 n-1 次：
        - 每次更新 n-1 个节点：
            - **每个节点的minDist**和**与它相邻的已访问节点minDist + 节点之间的距离**作比较；（看起来像O(n^3)的三重循环，实际上也就是每条边做松弛）
    - 所以时间复杂度为O(N * E)，最差的情况E = n*(n-1)，时间复杂度为 O(n^3)；
- 思路2：
    - 更能体现**对所有边进行松弛n-1次操作**，也就是O(N * E)的时间复杂度；
    - 通过判断 minDist[from] ==  INT32_MAX，来防止从未计算过的节点出发，与visited数组作用一样；

代码：
```c++
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
```