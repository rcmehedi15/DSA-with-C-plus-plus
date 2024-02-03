#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int source;
    cin >> source;

    vector<int> distance(n + 1, INF);
    distance[source] = 0;

    // Detect negative cycles using Bellman-Ford
    for (int i = 1; i <= n - 1; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 1; u <= n; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                cout << "Negative Cycle Detected\n";
                return 0;
            }
        }
    }

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i) {
        int destination;
        cin >> destination;

        if (distance[destination] == INF) {
            cout << "Not Possible\n";
        } else {
            cout << distance[destination] << "\n";
        }
    }

    return 0;
}
