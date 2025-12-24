#include <bits/stdc++.h>
#include <queue>
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

const int inf = LLONG_MAX;
const int ninf = -1 * inf;

void solve( ) {
        int n, m;
        cin >> n >> m;
        vector<vector<pii>> adj(n + 1);
        for (int i = 0; i < m; i++) {
                int a, b, w;
                cin >> a >> b >> w;
                adj[a].push_back({b, w});
                adj[b].push_back({a, w});
        }

        vector<int> sarr(n + 1, inf);
        sarr[1] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({sarr[1], 1});

        vector<int> par(n + 1, -1);
        while (!pq.empty( )) {
                auto [cost, node] = pq.top( );
                pq.pop( );
                if (cost > sarr[node]) continue;
                for (auto [nxtNode, nxtCost] : adj[node]) {
                        if (nxtCost + cost < sarr[nxtNode]) {
                                sarr[nxtNode] = nxtCost + cost;
                                pq.push({sarr[nxtNode], nxtNode});
                                par[nxtNode] = node;
                        }
                }
        }

        if (sarr[n] == inf) {
                cout << -1 << endl;
                return;
        }

        vector<int> spath;
        int dest = n;
        while (dest != 1) {
                spath.push_back(dest);
                dest = par[dest];
        }
        spath.push_back(1);

        reverse(spath.begin( ), spath.end( ));
        for (int &i : spath) cout << i << " ";
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
