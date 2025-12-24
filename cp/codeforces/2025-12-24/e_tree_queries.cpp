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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        /* path from root -> node such that all other nodes in the query
         * vector are in the path or at a distance 1 from the path
         */

        vector<int> par(n + 1, -1);
        vector<int> dep(n + 1, 0);

        vector<int> inTime(n + 1, 0);
        vector<int> outTime(n + 1, 0);
        int time = 0;

        auto dfs = [&](auto &go, int root, int p, int depth) -> void {
                par[root] = p;
                dep[root] = depth;
                inTime[root] = time++;
                for (auto it : adj[root]) {
                        if (it != p) {
                                go(go, it, root, depth + 1);
                        }
                }
                outTime[root] = time++;
        };
        dfs(dfs, 1, -1, 0);

        auto isAncs = [&](int node, int ancs) -> bool {
                return inTime[ancs] <= inTime[node] && outTime[node] <= outTime[ancs];
        };

        while (m--) {
                int k;
                cin >> k;
                vector<int> nodes(k);
                for (int &i : nodes) cin >> i;

                int deepest = nodes[0];
                for (auto it : nodes) {
                        if (dep[it] > dep[deepest]) {
                                deepest = it;
                        }
                }
                for (int &it : nodes) {
                        if (it != 1 && it != deepest) {
                                it = par[it];
                        }
                }

                bool flag = true;
                for (int it : nodes) {
                        if (!isAncs(deepest, it)) {
                                flag = false;
                                break;
                        }
                }

                cout << (flag ? "YES" : "NO") << endl;
        }
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
