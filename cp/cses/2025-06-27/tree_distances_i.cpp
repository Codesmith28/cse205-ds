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
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<pii> uv;
    vector<vector<int>> adj(n + 1);
    int fnode;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (!fnode) fnode = u;
    }

    vector<int> in_dp(n + 1, 0);
    vector<int> out_dp(n + 1, 0);

    auto in_dfs = [&](auto &&go, int node, int par) -> void {
        for (auto it : adj[node]) {
            if (it != par) {
                go(go, it, node);
                in_dp[node] = max(in_dp[node], 1 + in_dp[it]);
            }
        }
    };

    auto out_dfs = [&](auto &&go, int node, int par) -> void {
        int mx1, mx2;
        mx1 = mx2 = -1;

        for (auto it : adj[node]) {
            if (it != par) {
                if (in_dp[it] > mx1) {
                    mx2 = mx1;
                    mx1 = in_dp[it];
                } else if (in_dp[it] > mx2) {
                    mx2 = in_dp[it];
                }
            }
        }

        for (int it : adj[node]) {
            if (it != par) {
                int use = (in_dp[it] == mx1) ? mx2 : mx1;
                out_dp[it] = 1 + max(out_dp[node], 1 + use);
                go(go, it, node);
            }
        }
    };

    in_dfs(in_dfs, fnode, -1);
    out_dfs(out_dfs, fnode, -1);

    for (int i = 1; i <= n; i++) cout << max(in_dp[i], out_dp[i]) << " ";
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
