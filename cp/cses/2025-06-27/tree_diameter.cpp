#include <bits/stdc++.h>
#include <pthread.h>
#include <utility>
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

    int fnode = 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (!fnode) fnode = u;
    }

    auto bfs = [&](int start) -> pii {
        queue<int> q;
        q.push(start);
        vector<int> dist(n + 1, -1);
        dist[start] = 0;

        while (!q.empty( )) {
            int node = q.front( );
            q.pop( );
            for (auto it : adj[node]) {
                if (dist[it] == -1) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        int mx_dist = 0;
        int mx_node = start;
        for (int i = 0; i <= n; i++) {
            if (dist[i] > mx_dist) {
                mx_dist = dist[i];
                mx_node = i;
            }
        }

        return make_pair(mx_node, mx_dist);
    };

    auto [far, _] = bfs(fnode);
    auto [far2, diam] = bfs(far);

    cout << diam << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve( );
    }

    return 0;
}
