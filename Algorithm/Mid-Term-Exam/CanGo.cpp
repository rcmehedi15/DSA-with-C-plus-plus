#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int source;
    cin >> source;

    int q;
    cin >> q;

    while (q--) {
        int dest, cost;
        cin >> dest >> cost;

        vector<int> dist(n + 1, INT_MAX);
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int current_dist = pq.top().first;
            pq.pop();

            if (current_dist > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (current_dist + w <= cost && current_dist + w < dist[v]) {
                    dist[v] = current_dist + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[dest] <= cost && dist[dest] != INT_MAX) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
