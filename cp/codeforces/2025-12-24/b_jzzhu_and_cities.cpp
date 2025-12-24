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
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<pii>> adj(n + 1);
        vector<pii> trains;
        // roads
        for (int i = 0; i < m; i++) {
                int u, v, x;
                cin >> u >> v >> x;
                adj[u].push_back({v, x});
                adj[v].push_back({u, x});
        }
        // trains
        for (int i = 0; i < k; i++) {
                int city, cost;
                cin >> city >> cost;
                trains.push_back({city, cost});
                adj[1].push_back({city, cost});
                adj[city].push_back({1, cost});
        }

        // perform dijstra using roads only
        vector<int> spath(n + 1, inf);
        spath[1] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1}); // cost, node

        while (!pq.empty( )) {
                auto [cost, node] = pq.top( );
                pq.pop( );
                if (cost > spath[node]) continue;
                for (auto &[nbr, wt] : adj[node]) {
                        if (spath[nbr] > cost + wt) {
                                spath[nbr] = cost + wt;
                                pq.push({spath[nbr], nbr});
                        }
                }
        }

        vector<int> indeg(n + 1, 0);
        for (int u = 1; u <= n; u++) {
                for (auto &[v, wt] : adj[u]) {
                        if (spath[v] != inf && spath[v] == spath[u] + wt) {
                                indeg[v]++;
                        }
                }
        }

        int removed = 0;
        for (auto &it : trains) {
                int city = it.first;
                int cost = it.second;
                if (spath[city] < cost) {
                        removed++;
                } else if (spath[city] == cost) {
                        if (indeg[city] > 1) { // if other paths exist
                                removed++;
                                indeg[city]--;
                        }
                }
        }

        cout << removed << endl;
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
