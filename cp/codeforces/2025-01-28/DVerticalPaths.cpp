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
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<vector<int>> reach(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        if (p[i] == i) continue;
        reach[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }

    vector<bool> vis(n + 1, false);
    vector<vector<int>> seqs;

    auto dfs = [&](auto &&self, int node, vector<int> &path) -> void {
        vis[node] = true;
        path.push_back(node);

        for (int par : reach[node]) {
            if (!vis[par]) {
                self(self, par, path);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (adj[i].empty( ) && !vis[i]) {
            vector<int> path;
            dfs(dfs, i, path);
            reverse(path.begin( ), path.end( ));
            seqs.push_back(path);
        }
    }

    cout << seqs.size( ) << endl;
    for (auto &seq : seqs) {
        cout << seq.size( ) << endl;
        for (int i : seq) cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
