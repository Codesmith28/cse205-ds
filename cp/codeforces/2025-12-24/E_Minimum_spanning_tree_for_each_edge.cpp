#include <bits/stdc++.h>
#include <vector>
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

class DSU {
      private:
        vector<int> Parent, Rank, Size;

      public:
        DSU(int n) {
                Parent.resize(n + 1);
                Rank.resize(n + 1, 1);
                Size.resize(n + 1, 1);
                for (int i = 0; i <= n; i++) Parent[i] = i;
        }

        int Find(int x) {
                if (x != Parent[x]) Parent[x] = Find(Parent[x]);
                return Parent[x];
        }

        bool Union(int x, int y) {
                int xset = Find(x), yset = Find(y);
                if (xset != yset) {
                        if (Rank[xset] < Rank[yset]) {
                                Parent[xset] = yset;
                                Size[yset] += Size[xset];
                        } else {
                                Parent[yset] = xset;
                                Size[xset] += Size[yset];
                                if (Rank[xset] == Rank[yset]) Rank[xset]++;
                        }
                        return true;
                }
                return false;
        }

        int getSize(int x) {
                return Size[Find(x)];
        }
};

struct Edge {
        int u, v, w, idx;
};

class LCA {
      private:
        const int LOG = 20;
        int n;
        vector<vector<pii>> tree; //{node, wt}
        vector<vector<int>> ancs, mxEdge;
        vector<int> depth;

        void preDFS(int node, int par, int wt) {
                ancs[node][0] = par;
                mxEdge[node][0] = wt;

                for (int i = 1; i < LOG; i++) {
                        if (ancs[node][i - 1] != -1) {
                                ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
                                mxEdge[node][i] = max(mxEdge[node][i - 1], mxEdge[mxEdge[node][i - 1]][i - 1]);
                        }
                }
                for (auto &it : tree[node]) {
                        if (it.first != par) {
                                depth[it.first] = depth[node] + 1;
                                preDFS(it.first, node, it.second);
                        }
                }
        }

      public:
        LCA(int n, vector<vector<pii>> &tree, int root) : n(n), tree(tree) {
                ancs.assign(n + 1, vector<int>(LOG, -1));
                mxEdge.assign(n + 1, vector<int>(LOG, 0));
                depth.assign(n + 1, 0);
                preDFS(root, -1, 0);
        }

        int getMxWtOnPath(int a, int b) {
                if (depth[a] > depth[b]) swap(a, b);

                int res = 0;
                int diff = depth[b] - depth[a];

                // bring b to the same depth as a
                for (int i = 0; i < LOG; i++) {
                        if ((diff >> i) & 1) {
                                res = max(res, mxEdge[b][i]);
                                b = ancs[b][i];
                        }
                }

                if (a == b) return res;

                // common lift till same parent
                for (int i = LOG - 1; i >= 0; i--) {
                        if (ancs[a][i] != ancs[b][i]) {
                                res = max({res, mxEdge[a][i], mxEdge[b][i]});
                                a = ancs[a][i];
                                b = ancs[b][i];
                        }
                }

                return max({res, mxEdge[a][0], mxEdge[b][0]});
        }
};

void solve( ) {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                edges.push_back({u, v, w, i});
        }

        // MST:
        sort(edges.begin( ), edges.end( ), [](Edge a, Edge b) {
                return a.w < b.w;
        });

        DSU dsu(n);
        vector<vector<pii>> adj;

        int mstWt = 0;
        for (auto &it : edges) {
                if (dsu.Union(it.u, it.v)) {
                        mstWt += it.w;
                        adj[it.u].emplace_back(it.v, it.w);
                        adj[it.v].emplace_back(it.u, it.w);
                }
        }

        LCA lca(n, adj, 1);

        vector<int> res(m);
        for (auto &it : edges) {
                int heaviest = lca.getMxWtOnPath(it.u, it.v);
                res[it.idx] = mstWt - heaviest + it.w;
        }

        for (int &i : res) cout << i << " ";
        cout << endl;
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