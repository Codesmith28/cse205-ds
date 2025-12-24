#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    // Read edges and build adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // Convert to 0-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check if the graph is a tree: must have n-1 edges for n nodes
    if (m != n - 1) {
        cout << "NO" << endl;
        return;
    }

    // DFS to assign parents and check connectivity
    vector<int> par(n, -1); // par[i] = -1 means unvisited, par[i] = parent index (0-based)
    vector<bool> visited(n, false);
    int root = 0; // Arbitrarily choose node 0 as root

    auto dfs = [&](auto &&self, int node, int parent) -> void {
        visited[node] = true;
        par[node] = parent; // Store parent (0-based, -1 for root)
        for (int v : adj[node]) {
            if (!visited[v]) {
                self(self, v, node);
            }
        }
    };

    dfs(dfs, root, -1);

    // Check if all nodes are visited (graph is connected)
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    // Output parent array (convert to 1-based for output)
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) {
            cout << 0 << " "; // Root has no parent
        } else {
            cout << par[i] + 1 << " "; // Convert to 1-based indexing
        }
    }
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
