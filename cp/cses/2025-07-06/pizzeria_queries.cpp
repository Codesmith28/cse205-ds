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

const int inf = 1e18;
const int ninf = -1 * inf;

struct segtree {
    vector<int> tree, lazy;
    int n;

    segtree(int sz) {
        n = sz;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    /// Build the segment tree from a 0-based array `arr`
    void build(vector<int> &arr, int node, int st, int en) {
        if (st == en) {
            tree[node] = arr[st];
        } else {
            int mid = st + (en - st) / 2;
            build(arr, 2 * node, st, mid);
            build(arr, 2 * node + 1, mid + 1, en);
            // tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    /// Query max in range [left, right] on 0-based array
    int query(int node, int st, int en, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += (en - st + 1) * lazy[node];
            if (st != en) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (right < st || en < left) return inf;
        if (left <= st && en <= right) return tree[node];

        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        // return max(h1, h2);
        return min(h1, h2);
    }

    /// Add `val` to range [left, right] on 0-based array (lazy)
    void range_update(int node, int st, int en, int left, int right, int val) {
        if (lazy[node] != 0) {
            tree[node] += (en - st + 1) * lazy[node];
            if (st != en) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (right < st || en < left) return;
        if (left <= st && en <= right) {
            tree[node] += (en - st + 1) * val;
            if (st != en) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = st + (en - st) / 2;
        range_update(2 * node, st, mid, left, right, val);
        range_update(2 * node + 1, mid + 1, en, left, right, val);
        // tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    /// Point update: set a[idx] = val on 0-based array
    void pt_update(int node, int st, int en, int idx, int val) {
        if (st == en) {
            tree[node] = val;
        } else {
            int mid = st + (en - st) / 2;
            if (idx <= mid)
                pt_update(2 * node, st, mid, idx, val);
            else
                pt_update(2 * node + 1, mid + 1, en, idx, val);
            // tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
};

void solve( ) {
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<int> larr(n + 1), rarr(n + 1);
    for (int i = 1; i <= n; i++) {
        larr[i] = p[i] - i;
        rarr[i] = p[i] + i;
    }

    segtree left(n + 1);
    segtree right(n + 1);

    left.build(larr, 1, 1, n);
    right.build(rarr, 1, 1, n);

    while (q--) {
        int t, k, x;
        cin >> t;
        if (t == 1) {
            cin >> k >> x;
            p[k] = x;
            larr[k] = p[k] - k;
            rarr[k] = p[k] + k;
            left.pt_update(1, 1, n, k, larr[k]);
            right.pt_update(1, 1, n, k, rarr[k]);
        } else if (t == 2) {
            cin >> k;
            int l = left.query(1, 1, n, 1, k);
            int r = right.query(1, 1, n, k, n);
            cout << min(l + k, r - k) << endl;
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
