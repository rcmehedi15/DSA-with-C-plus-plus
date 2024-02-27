#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct Subset {
    int parent, rank;
};

Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
}

void KruskalMST(Graph* graph, int &removedRoads, int &minCost) {
    int V = graph->V;
    vector<Edge> result(V - 1);
    int e = 0, i = 0;

    sort(graph->edges.begin(), graph->edges.end(), comp);

    Subset* subsets = new Subset[(V * sizeof(Subset))];

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    if (e < V - 1) {
        removedRoads = graph->E - e;
        minCost = -1; // Indicate not possible
    } else {
        minCost = 0;
        for (i = 0; i < e; ++i) {
            minCost += result[i].weight;
        }
        removedRoads = graph->E - e;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph* graph = createGraph(N, M);
    for (int i = 0; i < M; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph->edges.push_back({src, dest, weight});
    }

    int removedRoads, minCost;
    KruskalMST(graph, removedRoads, minCost);

    if (minCost == -1)
        cout << "Not Possible" << endl;
    else
        cout << removedRoads << " " << minCost << endl;

    return 0;
}
