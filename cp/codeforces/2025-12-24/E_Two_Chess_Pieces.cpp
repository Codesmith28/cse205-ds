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

/// Least Common Ancestor of 2 nodes using Binary Lifting
class LCA {
      private:
        const int LOG = 21;
        int n, root;
        vector<vector<int>> &adj;
        vector<vector<int>> ancs;
        vector<int> depth;

        void preDfs(int node, int par) {
                ancs[node][0] = par;
                if (par != -1) {
                        depth[node] = depth[par] + 1;
                }
                for (int i = 1; i < LOG; i++) {
                        if (ancs[node][i - 1] != -1) ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
                }
                for (int it : adj[node]) {
                        if (it != par) preDfs(it, node);
                }
        }

      public:
        LCA(int n, vector<vector<int>> &adj, int root) : n(n), adj(adj), root(root) {
                ancs.resize(n + 1, vector<int>(LOG, -1));
                depth.resize(n + 1, 0);
                preDfs(root, -1);
        }

        int getLCA(int a, int b) {
                if (depth[a] > depth[b]) swap(a, b);

                // bring b to the same depth as a
                int diff = depth[b] - depth[a];
                for (int i = 0; i < LOG; i++) {
                        if (diff & (1 << i)) {
                                b = ancs[b][i];
                        }
                }
                if (a == b) return a;

                // common lift till same parent
                for (int i = LOG - 1; i >= 0; i--) {
                        if (ancs[a][i] != -1 && ancs[a][i] != ancs[b][i]) {
                                a = ancs[a][i];
                                b = ancs[b][i];
                        }
                }
                return ancs[a][0];
        }

        int getAncs(int node, int lvl) {
                return ancs[node][lvl];
        }

        int getDepth(int node) {
                return depth[node];
        }

        int getDist(int a, int b) {
                int lca = getLCA(a, b);
                return (depth[a] - depth[lca]) + (depth[b] - depth[lca]);
        }
};

void solve( ) {
        int n, d;
        cin >> n >> d;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        int m1;
        cin >> m1;
        vector<bool> needA(n + 1, 0);
        for (int i = 0; i < m1; i++) {
                int x;
                cin >> x;
                needA[x] = 1;
        }

        int m2;
        cin >> m2;
        vector<int> needB(n + 1, 0);
        for (int i = 0; i < m2; i++) {
                int x;
                cin >> x;
                needB[x] = 1;
        }

        int root = 1;
        LCA lca(n, adj, root);

        // one must pass through the dth ancestor of the other in order to not violate the connstraint

        vector<int> inTime(n + 1);
        int time = 0;

        auto dfs = [&](auto &&go, int node, int par) -> void {
                inTime[node] = ++time;
                for (auto it : adj[node]) {
                        if (it != par) go(go, it, node);
                }
        };
        dfs(dfs, root, -1);
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
