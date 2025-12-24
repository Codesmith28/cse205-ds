#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int INF = LLONG_MAX;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Initialize distance for each pair of nodes
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    // Reading edges
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        dist[a][b] = min(dist[a][b], cost);
        dist[b][a] = min(dist[b][a], cost); // since the graph is undirected
    }

    // Floyd-Warshall algorithm to compute all-pairs shortest paths
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Answer the queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}