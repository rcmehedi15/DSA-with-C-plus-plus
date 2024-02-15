#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj; // adjacency list representation of the graph
vector<bool> visited; // to keep track of visited vertices
int cycleEdgesCount; // count of edges forming cycles

void dfs(int v, int parent) {
    visited[v] = true; // mark the current vertex as visited
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, v); // recursively visit adjacent vertices
        } else if (u != parent) {
            // if u is visited and not the parent of current vertex,
            // it means we have encountered a cycle
            cycleEdgesCount++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    visited.assign(n + 1, false);
    cycleEdgesCount = 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // perform DFS from each unvisited vertex
            dfs(i, -1);
        }
    }
    
    // Since each edge contributes to exactly one cycle,
    // the number of edges forming cycles will be half of cycleEdgesCount
    cout << cycleEdgesCount / 2 << endl;
    
    return 0;
}
