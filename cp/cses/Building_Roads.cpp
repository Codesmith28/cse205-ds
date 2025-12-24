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
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1, false);
    vector<int> ans;

    auto dfs = [&](int node, auto &&dfs) -> void {
        vis[node] = true;
        for (auto &child : adj[node]) {
            if (!vis[child]) {
                dfs(child, dfs);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            dfs(i, dfs);
        }
    }

    int sz = ans.size();

    if (sz == 1) {
        cout << 0 << endl;
    } else {
        cout << sz - 1 << endl;
        for (int i = 1; i < sz; i++) {
            cout << ans[0] << " " << ans[i] << endl;
        }
    }
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