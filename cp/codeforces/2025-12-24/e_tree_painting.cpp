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

void solve( ) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        vector<int> subtree(n + 1, 1);

        auto dfs = [&](auto &&go, int node, int parent) -> void {
                for (auto &child : adj[node]) {
                        if (child != parent) {
                                go(go, child, node);
                                subtree[node] += subtree[child];
                        }
                }
        };
        dfs(dfs, 1, -1);

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) dp[1] += subtree[i];

        auto dfs2 = [&](auto &&go, int node, int parent) -> void {
                for (auto &child : adj[node]) {
                        if (child != parent) {
                                // rerooting
                                int remTree = n - subtree[child];
                                dp[child] = dp[node] - subtree[child] + remTree;
                                go(go, child, node);
                        }
                }
        };
        dfs2(dfs2, 1, -1);

        // max sum of all subtrees from any root
        int res = *max_element(dp.begin( ) + 1, dp.end( ));
        cout << res << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
