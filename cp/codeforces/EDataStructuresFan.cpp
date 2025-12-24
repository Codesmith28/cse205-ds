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
int mod = 1e9 + 7;

struct SegTree {
    vector<int> tree;
    int n;

    SegTree(int sz) {
        n = sz;
        tree.resize(4 * n, 0);
    }

    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = start + (end - start) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, left, right);
        int p2 = query(2 * node + 1, mid + 1, end, left, right);

        return p1 + p2;
    }
};

void solve( ) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;
    string s;
    cin >> s;

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;

        } else {
            int g;
            cin >> g;

            int res = 0;
            for (int i = 0; i < n; i++)
                if (s[i] - '0' == g) res ^= arr[i];

            cout << res << endl;
        }
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
