#include <bits/stdc++.h>
using namespace std;

#define int  long long
#define endl "\n"

vector<vector<int>> adj;
vector<int> sub;
vector<bool> vis;
int n, k1, k2;
int ans;

void sub_dfs(int node, int par) {
    sub[node] = 1;
    for (int it : adj[node]) {
        if (it != par && !vis[it]) {
            sub_dfs(it, node);
            sub[node] += sub[it];
        }
    }
}

int centroid(int node, int par, int total) {
    for (int it : adj[node]) {
        if (it != par && !vis[it]) {
            if (sub[it] > total / 2) {
                return centroid(it, node, total);
            }
        }
    }
    return node;
}

void dep_dfs(int node, int par, int dep, vector<int> &cnt, bool add) {
    if (dep > k2) return;
    if (add) {
        for (int rem = k1 - dep; rem <= k2 - dep; rem++) {
            if (rem >= 0 && rem < cnt.size( )) {
                ans += cnt[rem];
            }
        }
    } else {
        cnt[dep]++;
    }
    for (int it : adj[node]) {
        if (it != par && !vis[it]) {
            dep_dfs(it, node, dep + 1, cnt, add);
        }
    }
}

void decompose(int node) {
    sub_dfs(node, -1);
    int total = sub[node];
    int cent = centroid(node, -1, total);
    vis[cent] = true;

    vector<int> cnt(k2 + 1, 0);
    cnt[0] = 1;

    for (int it : adj[cent]) {
        if (!vis[it]) {
            dep_dfs(it, cent, 1, cnt, true);  // Count paths ending at cent
            dep_dfs(it, cent, 1, cnt, false); // Add paths starting from cent
        }
    }

    for (int it : adj[cent]) {
        if (!vis[it]) {
            decompose(it);
        }
    }
}

void solve( ) {
    cin >> n >> k1 >> k2;

    adj.assign(n + 1, { });
    sub.assign(n + 1, 0);
    vis.assign(n + 1, false);
    ans = 0;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decompose(1);
    cout << ans << endl;
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
