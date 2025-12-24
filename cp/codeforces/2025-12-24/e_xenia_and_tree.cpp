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

const int inf = 1e6;

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

        int getDistAncs(int node, int dist) {
                for (int i = 0; i < LOG; i++) {
                        if (dist & (1 << i)) {
                                node = ancs[node][i];
                        }
                }
                return node;
        }

        int getDist(int a, int b) {
                int lca = getLCA(a, b);
                return (depth[a] - depth[lca]) + (depth[b] - depth[lca]);
        }
};

void solve( ) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
                int a, b;
                cin >> a >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
        }

        LCA lca(n, adj, 1);
        vector<int> minDist(n + 1, inf); // current state
        queue<int> q;                    // buffer changing queries

        // mutlisourced BFS
        auto bfs = [&](queue<int> &q) -> void {
                queue<int> bfsQ;
                while (!q.empty( )) {
                        minDist[q.front( )] = 0;
                        bfsQ.push(q.front( ));
                        q.pop( );
                }
                while (!bfsQ.empty( )) {
                        int node = bfsQ.front( );
                        bfsQ.pop( );
                        for (auto &it : adj[node]) {
                                if (minDist[it] > minDist[node] + 1) {
                                        minDist[it] = minDist[node] + 1;
                                        bfsQ.push(it);
                                }
                        }
                }
        };

        // initial state
        minDist[1] = 0;
        q.push(1);
        bfs(q);

        // if t == 1 -> paint v as red
        // if t == 2 -> query the nearest red node from
        int SQRT = (int)(sqrt(m)) + 1;
        while (m--) {
                int t, v;
                cin >> t >> v;
                if (t == 1) {
                        // buffer the changing queries
                        // if buffer overflows, process all the buffered queries and clear the buffer
                        q.push(v);
                        if (q.size( ) >= SQRT) {
                                bfs(q);
                        }
                } else {
                        // compare the answers from the current states, and the buffered transitions
                        int res = minDist[v];
                        queue<int> tempQ = q; // copy the buffer
                        while (!tempQ.empty( )) {
                                int redNode = tempQ.front( );
                                tempQ.pop( );
                                int dist = lca.getDist(v, redNode);
                                res = min(res, dist);
                        }
                        cout << res << endl;
                }
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
