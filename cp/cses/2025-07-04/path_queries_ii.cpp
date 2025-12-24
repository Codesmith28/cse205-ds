#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

/// segment tree for range maximum queries
struct segtree {
    vector<int> tree;
    int n;

    segtree(int sz) {
        n = sz;
        tree.resize(4 * n, ninf);
    }

    void build(vector<int> &arr, int node, int st, int en) {
        if (st == en) {
            tree[node] = arr[st];
        } else {
            int mid = st + (en - st) / 2;
            build(arr, 2 * node, st, mid);
            build(arr, 2 * node + 1, mid + 1, en);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int st, int en, int left, int right) {
        if (right < st || en < left) return ninf;
        if (left <= st && en <= right) return tree[node];
        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        return max(h1, h2);
    }

    void pt_update(int node, int st, int en, int idx, int val) {
        if (st == en) {
            tree[node] = val;
        } else {
            int mid = st + (en - st) / 2;
            if (idx <= mid) {
                pt_update(2 * node, st, mid, idx, val);
            } else {
                pt_update(2 * node + 1, mid + 1, en, idx, val);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
};

/// Heavy-Light Decomposition (HLD) for path queries
vector<int> parent, depth, sub, heavy, head, pos;
vector<vector<int>> adj;
int cur_pos;

/// assigns parent, depth, sub, and heavy arrays using DFS
void assign_dfs(int node, int par, vector<vector<int>> &adj) {
    sub[node] = 1;
    for (auto &child : adj[node]) {
        if (child != par) {
            parent[child] = node;
            depth[child] = depth[node] + 1;
            assign_dfs(child, node, adj);
            sub[node] += sub[child];
            if (heavy[node] == -1 || sub[heavy[node]] < sub[child]) {
                heavy[node] = child;
            }
        }
    }
}

/// decomposes the tree into heavy-light segments
int decompose_dfs(int node, int h, vector<vector<int>> &adj) {
    head[node] = h;
    pos[node] = cur_pos++;
    if (heavy[node] != -1) {
        decompose_dfs(heavy[node], h, adj);
    }
    for (auto &child : adj[node]) {
        if (child == parent[node] || child == heavy[node]) continue;
        decompose_dfs(child, child, adj);
    }
    return 0;
}

void solve( ) {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i];
    adj.assign(n + 1, vector<int>( ));
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /// initialize HLD structures
    auto hld_init = [&]( ) -> void {
        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        sub.assign(n + 1, 0);
        heavy.assign(n + 1, -1);
        head.assign(n + 1, -1);
        pos.assign(n + 1, -1);
        cur_pos = 0;

        assign_dfs(1, -1, adj);
        decompose_dfs(1, 1, adj);
    };
    hld_init( );

    /// build segment tree for path queries
    vector<int> seg_arr(n);
    for (int i = 1; i <= n; i++) seg_arr[pos[i]] = val[i];
    segtree seg(n);
    seg.build(seg_arr, 1, 0, n - 1);

    /// query path maximums using HLD and segment tree
    auto query_path = [&](int a, int b) -> int {
        int max_val = ninf;
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) swap(a, b);
            max_val = max(max_val, seg.query(1, 0, n - 1, pos[head[a]], pos[a]));
            a = parent[head[a]];
        }
        if (depth[a] > depth[b]) swap(a, b);
        max_val = max(max_val, seg.query(1, 0, n - 1, pos[a], pos[b]));
        return max_val;
    };

    /// prepare for LCA queries
    vector<vector<int>> ancs(n + 1, vector<int>(21, -1));
    auto pre_dfs = [&](auto &&go, int node, int par) -> void {
        ancs[node][0] = par;
        for (int i = 1; i < 21; i++) {
            if (ancs[node][i - 1] != -1) {
                ancs[node][i] = ancs[ancs[node][i - 1]][i - 1];
            }
        }
        for (int it : adj[node]) {
            if (it != par) {
                depth[it] = depth[node] + 1;
                go(go, it, node);
            }
        }
    };
    pre_dfs(pre_dfs, 1, -1);

    auto lca = [&](int a, int b) -> int {
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        for (int i = 20; i >= 0; i--) {
            if (diff & (1LL << i)) {
                b = ancs[b][i];
            }
        }
        if (a == b) return a;
        for (int i = 20; i >= 0; i--) {
            if (ancs[a][i] != -1 && ancs[a][i] != ancs[b][i]) {
                a = ancs[a][i];
                b = ancs[b][i];
            }
        }
        return ancs[a][0];
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            seg.pt_update(1, 0, n - 1, pos[s], x);
        } else if (t == 2) {
            int a, b;
            cin >> a >> b;
            int l = lca(a, b);
            int ans = max(query_path(a, l), query_path(b, l));
            cout << ans << " ";
        }
    }
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    while (test_cases--) {
        solve( );
    }

    return 0;
}
