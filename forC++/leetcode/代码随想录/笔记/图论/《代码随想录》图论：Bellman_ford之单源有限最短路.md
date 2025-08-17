#### （卡码网）96.城市间货物运输III

思路：
- 1.本题与前面几道题的区别在于：
    - 规定了起点src，终点dst，最多可经过的城市数k，且没有要求检测负权回路；
    - 起点可以设置 minDist[src] = 0 来实现，终点是在结果输出时有效 minDist[dst]；
    - 关于 k，最多可经过 k 个城市，也就是最短路径上的节点最多有 k + 2 个，边最多有 k + 1 条；

- 2.本题要考虑负权回路的影响，如果只用同一个minDist数组，一次松弛会在负权回路的几条边循环更新：
    - 如：输入示例：
        ```
        4 4     
        1 2 -1
        2 3 1
        3 1 -1
        3 4 1
        1 4 3
        ```
        有四个节点，四条边，src为1，dst为2，k为3（需要松弛4次）

        ![Capture_20241209_192347.jpg](http://cdn.kamacoder.com/6756d5b01e376-phpAKnaJ4.jpg) 

        |minDist|1|2|3|4|
        |-|-|-|-|-|
        |初始化|0|inf|inf|inf| 
        |第1次松弛|-1|-1|0|1| 
        |第2次松弛|-2|-2|-1|0| 
        |第3次松弛|-3|-3|-2|-1| 
        |第4次松弛|-4|-4|-3|-2| 

        ![Capture_20241209_193015.jpg](http://cdn.kamacoder.com/6756d5bcec37e-php6Lll73.jpg) 

        在第一次松弛时：
        - minDist[2] = minDist[1] + val[1][2]，因为 minDist[1] + val[1][2] < minDist[2]；
        - minDist[3] = minDist[2] + val[2][3]，因为 minDist[2] + val[2][3] < minDist[3]；
        - minDist[4] = minDist[3] + val[3][4]，因为 minDist[3] + val[3][4] < minDist[4]；
        - minDist[1] = minDist[3] + val[3][1]，因为 minDist[3] + val[3][1] < minDist[1]；

        可以看出：在**使用同一个minDist数组**时，会出现更新完一条边的结束节点的minDist后，会把另一条边的出发节点的minDist值**覆盖**了，导致在遍历所有边时很多**深度大于松弛次数的节点**也更新了。
        
        如果存在负权回路，导致一次松弛就把一些不该松弛的边处理了，而且首尾相连，此时层数关系已经没有了(minDist环形更新)，松弛已经失去意义了。

        那么为什么：同样也是一个 minDist 数组，在图中没有负权回路时，使用同一个数组导致的**覆盖**不会影响结果？
        这是因为：假设 minDist[i] 在**节点 i 能距离起点最远的层数**--假如为 c，当松弛次数大于等于 c 时，minDist[i] 便不会改变了。

        ![Capture_20241209_193003.jpg](http://cdn.kamacoder.com/6756d860b379d-phpcWirfl.jpg) 

- 3.所以图中有负权回路时，minDist数组 应当保证不能被覆盖，所以考虑使用二维数组 `vector<vector<int>> minDist`，如 minDist[i][j] 表示第 i 轮松弛的 节点j 距离 节点src 的最短距离。
    - 效果如下：
    
    ![Capture_20241209_193139.jpg](http://cdn.kamacoder.com/6756db5cd74e2-phpP976nq.jpg) 

    最短距离为 1，最短路径为 1 -> 2 -> 3 -> 4；
    负权回路只影响后续回路中的最小距离，不影响路径离开回路后的回路外的结果，因为 minDist 已经将结果拷贝到下一层；

- 4.所以只要保证 minDist数组 不存在覆盖问题，就可以将负权回路考虑进最终结果：
    - 对于 Bellman-ford算法，主要改动有：
        - 将 minDist 换为二维数组；
        - 将起点 minDist[0][src] 初始化为 0，其他初始化为 INT32_MAX；
        - 控制松弛次数为 k + 1，每次根据 minDist[i - 1][?] 来更新；
    - 对于 SPFA算法，因为指向队列中的节点的边不会更新，所以不存在覆盖问题，主要改动有：
        - 将起点 minDist[src] 初始化为 0，其他初始化为 INT32_MAX；
        - 控制松弛次数为 k + 1，松弛次数也就是队列层数可以通过额外压入标志位来实现；

代码：
```c++
// Bellman-ford
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
```

```c++
// SPFA 有BUG

```