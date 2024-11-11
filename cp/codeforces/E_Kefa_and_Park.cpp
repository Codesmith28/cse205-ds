#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, bool> cat;
    for (int i = 1; i <= n; i++) {
        bool in;
        cin >> in;
        cat[i] = in;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    map<int, bool> leaf;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1 && i != 1) {
            leaf[i] = true;
        }
    }

    int path = 0;
    map<int, bool> vis;

    auto dfs = [&](int node, int consec, auto &&dfs) -> void {
        vis[node] = true;

        if (consec > m) return;
        if (leaf[node]) path++;

        for (auto ch : adj[node]) {
            if (!vis[ch]) {
                if (cat[ch]) {
                    dfs(ch, consec + 1, dfs);
                } else {
                    dfs(ch, 0, dfs);
                }
            }
        }
    };

    dfs(1, cat[1] ? 1 : 0, dfs);
    cout << path << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}