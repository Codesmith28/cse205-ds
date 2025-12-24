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

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool reached = false;
    vector<int> parent(n + 1, -1);
    vector<bool> vis(n + 1, false);

    queue<int> q;
    q.push(1);
    while (!q.empty() and !reached) {
        int curr = q.front();
        q.pop();

        for (auto it : adj[curr]) {
            if (!vis[it]) {
                vis[it] = true;
                parent[it] = curr;
                q.push(it);
                if (it == n) {
                    reached = true;
                    break;
                }
            }
        }
    }

    if (!reached) {
        cout << "IMPOSSIBLE\n";
        return;
    } else {
        vector<int> path;
        int curr = n;
        while (curr != 1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int i : path) cout << i << " ";
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