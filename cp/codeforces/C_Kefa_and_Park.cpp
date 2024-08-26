#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

vector<vector<int>> adj(1e6);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int &i : c) cin >> i;

    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y), adj[y].push_back(x);
    }

    int ans = 0;

    auto dfs = [&](int node, int parent, int consec, auto &&dfs) {
        if (consec > m) return;
        bool safe = true;

        for (auto &child : adj[node]) {
            if (child != parent) {
                safe = false; // leaf or not
                dfs(child, node, c[child] ? consec + 1 : 0, dfs);
            }
        }

        ans += safe;
    };

    dfs(0, -1, c[0], dfs);
    cout << ans << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}