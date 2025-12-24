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

struct BIT {
    int n;
    vector<int> tree;

    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0); // 1-based indexing
    }

    /// Add `val` to index `i` (1-based)
    void update(int i, int val) {
        while (i <= n) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    /// Prefix sum query: sum of elements in [1, i] (1-based)
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i -= (i & -i);
        }
        return res;
    }

    /// Range sum query: sum of elements in [l, r] (1-based)
    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve( ) {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, BIT> bitChain;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, x, d;
            cin >> v >> x >> d;
        } else if (t == 2) {
            int v;
            cin >> v;
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