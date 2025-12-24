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
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> vis;
    auto no_pair = [&](int u, int v) -> bool {
        return !vis.count(u) && !vis.count(v);
    };

    int cnt = 0;

    auto dfs = [&](auto &&go, int node, int par) -> void {
        for (auto it : adj[node]) {
            if (it != par) {
                go(go, it, node);
                if (no_pair(node, it)) {
                    vis.insert(node);
                    vis.insert(it);
                    cnt++;
                }
            }
        }
    };

    dfs(dfs, 1, -1);
    cout << cnt << endl;
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
