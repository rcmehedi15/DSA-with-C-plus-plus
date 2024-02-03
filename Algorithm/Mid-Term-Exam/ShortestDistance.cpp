#include <bits/stdc++.h>
using namespace std;

#define INF 1e18

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (long long)w);  
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int src, dest;
        cin >> src >> dest;

        if (dist[src][dest] == INF)
            cout << "-1\n";
        else
            cout << dist[src][dest] << "\n";
    }

    return 0;
}
