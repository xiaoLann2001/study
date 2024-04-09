#include <iostream>
#include <vector>
#include <limits>
#include <chrono>

using namespace std;
using namespace chrono;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

    Graph(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, INF)) {}

    // 添加边
    void addEdge(int u, int v, int weight) {
        adjacencyMatrix[u][v] = weight;
        adjacencyMatrix[v][u] = weight; // 假设是无向图
    }

    // 在距离集合中找到最小距离的顶点
    int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
        int minDist = INF, minIndex = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!sptSet[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    // Dijkstra算法
    void dijkstra(int src) {
        vector<int> dist(vertices, INF);
        vector<bool> sptSet(vertices, false);

        dist[src] = 0;

        auto start = high_resolution_clock::now();

        for (int count = 0; count < vertices - 1; ++count) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < vertices; ++v) {
                if (!sptSet[v] && adjacencyMatrix[u][v] != INF &&
                    dist[u] != INF && dist[u] + adjacencyMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjacencyMatrix[u][v];
                }
            }
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Dijkstra算法: 从源顶点" << src << "到所有其他顶点的最短距离:\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "顶点" << i << ": " << dist[i] << endl;
        }

        cout << "Dijkstra算法时间: " << duration.count() << " 微秒" << endl;
    }

    // Floyd-Warshall算法
    void floydWarshall() {
        vector<vector<int>> dist = adjacencyMatrix;

        auto start = high_resolution_clock::now();

        for (int k = 0; k < vertices; ++k) {
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "\nFloyd-Warshall算法: 所有顶点对之间的最短距离:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (dist[i][j] == INF) {
                    cout << "INF\t";
                } else {
                    cout << dist[i][j] << "\t";
                }
            }
            cout << endl;
        }

        cout << "Floyd-Warshall算法时间: " << duration.count() << " 微秒" << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 9);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    int sourceVertex = 0;
    g.dijkstra(sourceVertex);
    g.floydWarshall();

    return 0;
}
