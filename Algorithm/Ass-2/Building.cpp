#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest;
    long long weight;
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int src, int dest, long long weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = findParent(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        if (xset != yset) {
            if (rank[xset] < rank[yset])
                swap(xset, yset);
            parent[yset] = xset;
            if (rank[xset] == rank[yset])
                rank[xset]++;
        }
    }

    long long minCost() {
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
            return a.weight < b.weight;
        });

        long long minCost = 0;
        for (Edge& edge : edges) {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);
            if (x != y) {
                minCost += edge.weight;
                unionSets(parent, rank, x, y);
            }
        }

        int connectedComponents = count(parent.begin(), parent.end(), -1);
        if (connectedComponents > 1)
            return -1;
        return minCost;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);
    for (int i = 0; i < M; ++i) {
        int src, dest;
        long long weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src - 1, dest - 1, weight);
    }

    long long minCost = graph.minCost();
    cout << minCost << endl;

    return 0;
}
