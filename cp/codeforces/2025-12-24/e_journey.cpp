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
        int idx, src, des, w;
        Edge(int i, int s, int d, int w) : idx(i), src(s), des(d), w(w) {};
};

void solve( ) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges;
        map<int, int> deg;

        int baseWt = 0;
        for (int i = 0; i < m; i++) {
                int u, v, w;
                cin >> u >> v >> w;
                edges.emplace_back(i, u, v, w);
                deg[u]++, deg[v]++;
                baseWt += w;
        }

        set<int> odd, even;
        for (auto &[node, d] : deg) (d % 2 == 0 ? even.insert(node) : odd.insert(node));
        if (odd.empty( )) {
                cout << baseWt << endl;
                return;
        }

        DSU dsu(n + m + 1);
        vector<vector<int>> adj(n + m + 1);
        int last = n;
        for (auto [idx, src, des, wt] : edges) {
                int root = idx + n;
                last = max(last, root);
                adj[root].push_back(src);
                if (dsu.Union(src, des)) adj[root].push_back(des);
                dsu.Union(root, src);
                dsu.Union(root, des);
        }

        int extra = 0;
        auto dfs = [&](auto &&go, int node, int mnWt) -> int {
                if (node >= n) { // edge node
                        int nodeIdx = node - n;
                        mnWt = min(mnWt, edges[nodeIdx].w);
                }

                int currOdd = 0;
                // actual node
                if (node < n) currOdd = (odd.count(node) ? 1 : 0);
                for (auto it : adj[node]) {
                        currOdd += go(go, it, mnWt);
                }
                extra += (currOdd / 2) * mnWt;
                return currOdd % 2;
        };
        dfs(dfs, last, inf);

        cout << baseWt + extra << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
