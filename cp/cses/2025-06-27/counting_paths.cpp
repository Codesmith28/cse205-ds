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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ancs(n + 1, vector<int>(21, -1));
    vector<int> depth(n + 1, 0);

    auto pre_dfs = [&](auto &&go, int node, int par) -> void {
        ancs[node][0] = par;
        for (int i = 1; i < 21; i++) {
            if (ancs[node][i - 1] != -1) {
                ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
            }
        }
        for (int it : adj[node]) {
            if (it != par) {
                depth[it] = depth[node] + 1;
                go(go, it, node);
            }
        }
    };
    pre_dfs(pre_dfs, 1, -1);

    auto lca = [&](int a, int b) -> int {
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        for (int i = 20; i >= 0; i--) { // bring to same level
            if (diff & (1LL << i)) {
                b = ancs[b][i];
            }
        }
        if (a == b) return a; // if they are same, return either
        // bring both to their LCA
        for (int i = 20; i >= 0; i--) {
            if (ancs[a][i] != -1 && ancs[a][i] != ancs[b][i]) {
                a = ancs[a][i];
                b = ancs[b][i];
            }
        }
        return ancs[a][0];
    };

    vector<int> res(n + 1, 0);

    auto dfs = [&](auto &&go, int node, int par) -> void {
        for (int it : adj[node]) {
            if (it != par) {
                go(go, it, node);
                res[node] += res[it];
            }
        }
    };

    while (m--) {
        int a, b;
        cin >> a >> b;
        int lca_node = lca(a, b);
        res[a]++;
        res[b]++;
        res[lca_node]--;
        if (lca_node != 1) { // if lca is not root, decrement its parent
            res[ancs[lca_node][0]]--;
        }
    }
    dfs(dfs, 1, -1);

    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
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
