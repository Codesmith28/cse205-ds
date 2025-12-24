#include <bits/stdc++.h>
#include <csignal>
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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1, 0);
    vector<vector<int>> ancs(n + 1, vector<int>(20, -1));

    auto pre_dfs = [&](auto &&go, int node, int par) -> void {
        ancs[node][0] = par;
        for (int i = 1; i < 21; i++) {
            if (ancs[node][i - 1] != -1) {
                ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
            }
        }
        for (auto &it : adj[node]) {
            if (it != par) {
                depth[it] = depth[node] + 1;
                go(go, it, node);
            }
        }
    };
    pre_dfs(pre_dfs, 1, -1);

    // dist between two nodes:
    auto dist = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        int res = 0;

        for (int i = 20; i >= 0; i--) {
            if (diff & (1 << i)) {
                res += (1 << i);
                u = ancs[u][i];
            }
        }

        if (u == v) return res;

        for (int i = 20; i >= 0; i--) {
            if (ancs[u][i] != -1 && ancs[u][i] != ancs[v][i]) {
                res += (1 << i) * 2; // both edges to the LCA
                u = ancs[u][i];
                v = ancs[v][i];
            }
        }

        // one edge to LCA and one edge to the parent of LCA
        if (ancs[u][0] != -1) res += 2;
        return res;
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dist(a, b) << endl;
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
