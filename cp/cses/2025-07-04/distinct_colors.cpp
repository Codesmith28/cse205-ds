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
    vector<set<int>> cols(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cols[i].insert(x);
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n + 1);
    auto dfs = [&](auto &&go, int node, int par) -> void {
        for (auto it : adj[node]) {
            if (it != par) {
                go(go, it, node);
                if (cols[it].size( ) > cols[node].size( )) swap(cols[it], cols[node]);
                for (auto color : cols[it]) cols[node].insert(color);
            }
        }
        ans[node] = cols[node].size( );
    };
    dfs(dfs, 1, -1);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
