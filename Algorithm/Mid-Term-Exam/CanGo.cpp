#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the number of nodes and edges
    int n, m;
    cin >> n >> m;

    // Create an adjacency list to store the graph
    vector<pair<int, int>> adj[n + 1];

    // Read the edges and their costs
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Read the source node
    int source;
    cin >> source;

    // Read the number of test cases
    int q;
    cin >> q;

    // Process each test case
    while (q--) {
        int dest, cost;
        cin >> dest >> cost;

        // Perform BFS to find if there is a path from source to destination with at most the given cost
        vector<int> dist(n + 1, INT_MAX);
        dist[source] = 0;

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w <= cost && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }

        // Check if there is a path from source to destination with at most the given cost
        if (dist[dest] <= cost && dist[dest] != INT_MAX) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
