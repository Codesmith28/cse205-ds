
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

const int N = 1e5 + 2;
int tree[4 * N], a[N];

void build(int node, int st, int en) {
    if (st == en) {
        tree[node] = a[st];
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int l, int r) {
    if (st > r || en < l) {
        return 0;
    }

    if (st >= l && en <= r) {
        return tree[node];
    }

    int mid = (st + en) / 2;
    int p1 = query(2 * node, st, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, en, l, r);

    return p1 + p2;
}

void update(int node, int st, int en, int idx, int val) {
    if (st == en) {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;
    if (idx <= mid) {
        update(2 * node, st, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, en, idx, val);
    }

    // tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }

    build(1, 0, n - 1);

    int t; // Initialize t to a valid value
    while (m--) {
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;

            update(1, 0, n - 1, i, v);

        } else if (t == 2) {
            int l, r;
            cin >> l >> r;

            cout << query(1, 0, n - 1, l, r) << endl;
        }
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