#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
using ll = long long;

struct LCA {
    int n;
    int root;
    int LOG;
    vector<vector<int>> ancs;
    vector<int> depth;
    vector<int> tin, tout;
    int timer = 0;

    LCA( ) = default;
    LCA(int n_, const vector<vector<int>> &adj, int root_ = 1) {
        init(n_, adj, root_);
    }

    void init(int n_, const vector<vector<int>> &adj, int root_ = 1) {
        n = n_;
        root = root_;
        LOG = 1;
        while ((1 << LOG) <= n) ++LOG;
        ancs.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = ++timer;
            ancs[u][0] = p;
            depth[u] = (p == -1 ? 0 : depth[p] + 1);
            for (int v : adj[u])
                if (v != p) dfs(v, u);
            tout[u] = timer;
        };

        dfs(root, -1);

        for (int j = 1; j < LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (ancs[i][j - 1] != -1)
                    ancs[i][j] = ancs[ancs[i][j - 1]][j - 1];
                else
                    ancs[i][j] = -1;
            }
        }
    }

    int getLCA(int a, int b) const {
        if (a == -1) return b;
        if (b == -1) return a;
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        for (int j = 0; j < LOG; ++j)
            if (diff & (1 << j)) b = ancs[b][j];
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; --j) {
            if (ancs[a][j] != ancs[b][j]) {
                a = ancs[a][j];
                b = ancs[b][j];
            }
        }
        return ancs[a][0];
    }

    int dist(int a, int b) const {
        int c = getLCA(a, b);
        return depth[a] + depth[b] - 2 * depth[c];
    }
};

void solve( ) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int &i : p) cin >> i;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        adj[par].push_back(i);
        adj[i].push_back(par);
    }

    LCA lca(n, adj, 1);

    // Segment tree over values 0..n-1 storing whether values in interval lie on one path
    struct PathNode {
        bool empty = true;
        bool ok = true;
        int u = -1, v = -1;
    };

    struct SegTree {
        int N;
        vector<PathNode> seg;
        const LCA *lca = nullptr;

        SegTree( ) = default;
        SegTree(int n, const LCA *L) {
            init(n, L);
        }

        void init(int n, const LCA *L) {
            N = n;
            lca = L;
            seg.assign(4 * N, PathNode( ));
        }

        static PathNode make_leaf(int node) {
            PathNode p;
            p.empty = false;
            p.ok = true;
            p.u = p.v = node;
            return p;
        }

        PathNode mergeNode(const PathNode &a, const PathNode &b) const {
            if (a.empty) return b;
            if (b.empty) return a;
            PathNode res;
            res.empty = false;
            res.ok = false;
            if (!a.ok || !b.ok) return res;
            vector<int> cand = {a.u, a.v, b.u, b.v};
            sort(cand.begin( ), cand.end( ));
            cand.erase(unique(cand.begin( ), cand.end( )), cand.end( ));
            for (int i = 0; i < (int)cand.size( ); ++i) {
                for (int j = i; j < (int)cand.size( ); ++j) {
                    int x = cand[i], y = cand[j];
                    bool good = true;
                    int dxy = lca->dist(x, y);
                    for (int z : cand) {
                        if (lca->dist(x, z) + lca->dist(z, y) != dxy) {
                            good = false;
                            break;
                        }
                    }
                    if (good) {
                        res.ok = true;
                        res.u = x;
                        res.v = y;
                        return res;
                    }
                }
            }
            return res;
        }

        void build(const vector<int> &pos) {
            function<void(int, int, int)> dfs = [&](int idx, int l, int r) {
                if (l == r) {
                    seg[idx] = make_leaf(pos[l]);
                    return;
                }
                int mid = (l + r) >> 1;
                dfs(idx << 1, l, mid);
                dfs(idx << 1 | 1, mid + 1, r);
                seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
            };
            dfs(1, 0, N - 1);
        }

        void pointUpdate(int valueIndex, int nodePos) {
            function<void(int, int, int)> upd = [&](int idx, int l, int r) {
                if (l == r) {
                    seg[idx] = make_leaf(nodePos);
                    return;
                }
                int mid = (l + r) >> 1;
                if (valueIndex <= mid)
                    upd(idx << 1, l, mid);
                else
                    upd(idx << 1 | 1, mid + 1, r);
                seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
            };
            upd(1, 0, N - 1);
        }

        // returns largest r in [0..N-1] such that values [0..r] lie on a single path
        int maxPrefix( ) const {
            PathNode cur;
            cur.empty = true;
            cur.ok = true;
            function<int(int, int, int, const PathNode &)> go = [&](int idx, int l, int r, const PathNode &curNode) -> int {
                if (l == r) {
                    PathNode merged = mergeNode(curNode, seg[idx]);
                    return merged.ok ? l : l - 1;
                }
                int mid = (l + r) >> 1;
                PathNode leftMerged = mergeNode(curNode, seg[idx << 1]);
                if (leftMerged.ok)
                    return go(idx << 1 | 1, mid + 1, r, leftMerged);
                else
                    return go(idx << 1, l, mid, curNode);
            };
            return go(1, 0, N - 1, cur);
        }
    };

    vector<int> pos(n, -1); // pos[value] = node index (1-based)
    for (int i = 0; i < n; ++i) pos[p[i]] = i + 1;

    SegTree segt(n, &lca);
    segt.build(pos);

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            // nodes i and j (1-based) swap their values
            int vi = p[i - 1];
            int vj = p[j - 1];
            if (vi == vj) continue;
            swap(p[i - 1], p[j - 1]);
            // update pos
            pos[vi] = j;
            pos[vj] = i;
            // update segment tree leaves for values vi and vj
            segt.pointUpdate(vi, pos[vi]);
            segt.pointUpdate(vj, pos[vj]);
        } else if (t == 2) {
            int r = segt.maxPrefix( );
            cout << (r + 1) << '\n';
        }
    }
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