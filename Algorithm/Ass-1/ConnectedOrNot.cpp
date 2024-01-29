#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Create an adjacency list to represent the directed graph
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    int q;
    cin >> q;

    // Process each query
    for (int i = 0; i < q; i++) {
        int source, destination;
        cin >> source >> destination;

        // Check if there is a direct edge from source to destination or if they are the same node
        bool canReachDirectly = (source == destination) || find(adjList[source].begin(), adjList[source].end(), destination) != adjList[source].end();

        // Output the result
        cout << (canReachDirectly ? "YES" : "NO") << endl;
    }

    return 0;
}
