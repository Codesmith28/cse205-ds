#include <bits/stdc++.h>
using namespace std;

#define int  long long
#define endl "\n"

vector<vector<int>> adj;
vector<int> sub;
vector<bool> vis;
int n, k, ans;

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
        if (it != par && !vis[it] && sub[it] > total / 2) {
            return centroid(it, node, total);
        }
    }
    return node;
}

// first: count=true -> add to ans, count=false -> update cnt[]
void dep_dfs(int node, int par, int dep, vector<int> &cnt, bool count) {
    if (dep > k) return;
    if (count)
        ans += cnt[k - dep];
    else
        cnt[dep]++;
    for (int it : adj[node]) {
        if (it != par && !vis[it]) {
            dep_dfs(it, node, dep + 1, cnt, count);
        }
    }
}

void decompose(int node) {
    sub_dfs(node, -1);
    int total = sub[node];
    int cent = centroid(node, -1, total);
    vis[cent] = true;

    vector<int> cnt(k + 1, 0);
    cnt[0] = 1;

    for (int it : adj[cent]) {
        if (!vis[it]) {
            dep_dfs(it, cent, 1, cnt, true);  // 1. Count valid paths in current subtree using cnt from previous subtrees
            dep_dfs(it, cent, 1, cnt, false); // 2. Update cnt with current subtree
        }
    }

    for (int it : adj[cent]) {
        if (!vis[it]) {
            decompose(it);
        }
    }
}

void solve( ) {
    cin >> n >> k;
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
    solve( );
    return 0;
}
