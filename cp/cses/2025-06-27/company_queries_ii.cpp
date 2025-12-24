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
        adj[i].push_back(x);
    }

    vector<vector<int>> ancs(n + 1, vector<int>(21, -1));
    vector<int> depth(n + 1, 0);

    auto pre_dfs = [&](auto &&go, int node, int par) -> void {
        ancs[node][0] = par;
        if (par != -1) depth[node] = depth[par] + 1;

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

    // LCA of 2 nodes a and b:
    auto lca = [&](int a, int b) -> int {
        if (depth[a] > depth[b]) swap(a, b);

        // brnig on same level
        int diff = depth[b] - depth[a];
        for (int i = 20; i >= 0; i--) {
            if (diff & (1LL << i)) {
                b = ancs[b][i];
            }
        }
        if (a == b) return a;

        // common uplifting till their parents are same as now they are on same level:
        for (int i = 20; i >= 0; i--) {
            if (ancs[a][i] != -1 && ancs[a][i] != ancs[b][i]) {
                a = ancs[a][i];
                b = ancs[b][i];
            }
        }

        return ancs[a][0];
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
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
