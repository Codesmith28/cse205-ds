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

    // Build the segment tree
    void build(vector<int> &arr, int node, int st, int en) {
        if (st == en) {
            tree[node] = arr[st];
        } else {
            int mid = st + (en - st) / 2;
            build(arr, 2 * node, st, mid);
            build(arr, 2 * node + 1, mid + 1, en);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    // Query for sum in range [left, right]
    int query(int node, int st, int en, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += (en - st + 1) * lazy[node];
            if (st != en) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (right < st || en < left) return 0;
        if (left <= st && en <= right) return tree[node];
        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        return h1 + h2;
    }

    // range update in [left, right] by val
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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Point update at index idx
    void pt_update(int node, int st, int en, int idx, int val) {
        int curr_val = query(node, st, en, idx, idx);
        int delta = val - curr_val;
        range_update(node, st, en, idx, idx, delta);
    }
};

void solve( ) {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;

    segtree st(n);
    st.build(arr, 1, 0, n - 1);

    while (q--) {
        int t, a, b, u, k;
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> u;
            --a, --b;
            st.range_update(1, 0, n - 1, a, b, u);
        } else if (t == 2) {
            cin >> k;
            --k;
            cout << st.query(1, 0, n - 1, k, k) << endl;
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
