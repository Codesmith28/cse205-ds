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

    int fnode = 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (i == 0) fnode = u;
    }

    vector<int> sb_dp(n + 1, 0);
    vector<int> node_cnt(n + 1, 0);

    auto pre_dfs = [&](auto &&go, int node, int par) -> void {
        int sub = 0;
        int cnt = 1;

        for (auto it : adj[node]) {
            if (it != par) {
                go(go, it, node);
                cnt += node_cnt[it];
                sub += sb_dp[it] + node_cnt[it];
            }
        }

        sb_dp[node] = sub;
        node_cnt[node] = cnt;
    };

    pre_dfs(pre_dfs, fnode, -1);

    vector<int> ans(n + 1);
    ans[fnode] = sb_dp[fnode];

    auto dfs = [&](auto &&go, int node, int par) -> void {
        for (auto it : adj[node]) {
            if (it != par) {
                ans[it] = ans[node] + (n - node_cnt[it]) - node_cnt[it];
                go(go, it, node);
            }
        }
    };

    dfs(dfs, fnode, -1);
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
