#include <bits/stdc++.h>
#include <unordered_map>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_map<int, int> mp;
    auto dfs = [&](int curr, bool flag, auto &&dfs) -> bool {
        if (flag) mp[curr] = 1;
        else mp[curr] = 2;

        bool res = true;
        for (auto node : adj[curr]) {
            if (mp[node]) {
                if (mp[node] == mp[curr]) return false;
            } else {
                res = res and dfs(node, !flag, dfs);
            }
        }
        return res;
    };

    bool res = true;
    for (int i = 1; i < n + 1; i++) {
        if (!mp[i]) res = res and (dfs(i, true, dfs));
    }

    if (res) {
        for (int i = 1; i < n + 1; i++) cout << mp[i] << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    int a = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}