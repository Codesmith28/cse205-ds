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
    map<int, int> deg;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sub(n + 1);
    auto dfs = [&](auto &&go, int node, int par) -> void {
        sub[node] = 1;
        for (auto it : adj[node]) {
            if (it != par) {
                go(go, it, node);
                sub[node] += sub[it];
            }
        }
    };
    dfs(dfs, 1, -1);

    auto centroid = [&](auto &&go, int node, int par) -> int {
        int mx = 0, poss = 0;
        // get the maximum subtree size
        for (auto it : adj[node]) {
            if (it != par) {
                if (sub[it] > mx) {
                    mx = sub[it];
                    poss = it;
                }
            }
        }
        // if max subtree size is less than or equal to n/2, return the current node
        if (mx <= n / 2) return node;
        // otherwise, continue the search in the subtree with the maximum size
        return go(go, poss, node);
    };

    cout << centroid(centroid, 1, -1) << endl;
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
