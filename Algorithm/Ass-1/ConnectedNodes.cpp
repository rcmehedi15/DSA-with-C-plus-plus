#include <bits/stdc++.h>


using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Create an adjacency list to represent the graph
    vector<vector<int>> graph(n);
    
    // Read the edges and build the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int q;
    cin >> q;

    // Process each query
    for (int i = 0; i < q; ++i) {
        int query_node;
        cin >> query_node;

        // Find neighbors of the query_node
        vector<int> neighbors = graph[query_node];

        // Sort the neighbors in descending order
        sort(neighbors.rbegin(), neighbors.rend());

        // Output the result
        if (neighbors.empty()) {
            cout << -1;
        } else {
            for (int neighbor : neighbors) {
                cout << neighbor << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
