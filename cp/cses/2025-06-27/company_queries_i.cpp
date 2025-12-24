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

void solve( ) {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    vector<vector<int>> ancs(n + 1, vector<int>(21, -1));
    auto pre_dfs = [&](auto &&go, int node, int par) -> void {
        ancs[node][0] = par;
        for (int i = 1; i < 21; i++) {
            if (ancs[node][i - 1] != -1) {
                ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
            }
        }
        for (int it : adj[node]) {
            if (it != par) {
                go(go, it, node);
            }
        }
    };

    pre_dfs(pre_dfs, 1, -1);

    auto query = [&](int node, int k) -> int {
        for (int i = 20; i >= 0 && node != -1; i--) {
            if (k & (1LL << i)) {
                node = ancs[node][i];
            }
        }
        return node;
    };

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << endl;
    }
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
