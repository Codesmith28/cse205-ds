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

    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    int start = -1, end = -1;

    auto dfs = [&](int node, auto &&dfs) -> bool {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                parent[it] = node;
                if (dfs(it, dfs)) return true;
            } else if (it != parent[node]) {
                start = it;
                end = node;
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i < n + 1; i++) {
        if (!vis[i] and dfs(i, dfs)) break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        path.push_back(start);
        int curr = end;
        while (curr != start) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(start);

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
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
