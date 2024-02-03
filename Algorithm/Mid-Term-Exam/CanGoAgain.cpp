#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int nodes, int edges, vector<Edge>& graph, int source, vector<int>& dist) {
    dist[source] = 0;

    for (int i = 0; i < nodes - 1; ++i) {
        for (const Edge& edge : graph) {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    for (const Edge& edge : graph) {
        if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Negative Cycle Detected\n";
            exit(0);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<Edge> graph(edges);
    for (int i = 0; i < edges; ++i) {
        cin >> graph[i].src >> graph[i].dest >> graph[i].weight;
    }

    int source;
    cin >> source;

    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; ++i) {
        int destination;
        cin >> destination;

        vector<int> dist(nodes, INF);
        bellmanFord(nodes, edges, graph, source, dist);

        if (dist[destination] == INF) {
            cout << "Not Possible\n";
        } else {
            cout << dist[destination] << endl;
        }
    }

    return 0;
}
