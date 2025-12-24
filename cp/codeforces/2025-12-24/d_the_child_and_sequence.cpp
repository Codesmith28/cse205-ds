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

const int inf = 1e9;

struct Node {
        int sum, mxx; // sum of range and mx element of range
        Node(int sum, int mxx) : sum(sum), mxx(mxx) {
        }
};

Node merge(Node &a, Node &b) {
        int summ = a.sum + b.sum;
        int mxxx = max(a.mxx, b.mxx);
        return {summ, mxxx};
}

class SegTree {
      public:
        int n;
        vector<Node> tree;

        void build(int node, int start, int end, vector<int> &a) {
                if (start == end) {
                        tree[node] = {a[start], a[start]};
                        return;
                }
                int mid = start + (end - start) / 2;
                build(2 * node, start, mid, a);
                build(2 * node + 1, mid + 1, end, a);
                // tree[node] = tree[2 * node] + tree[2 * node + 1];
                tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        Node query(int node, int start, int end, int left, int right) {
                if (right < start || end < left) return {0, -inf};
                if (left <= start && end <= right) return tree[node];
                int mid = start + (end - start) / 2;
                Node q1 = query(2 * node, start, mid, left, right);
                Node q2 = query(2 * node + 1, mid + 1, end, left, right);
                // return q1 + q2;
                return merge(q1, q2);
        }

        void rangeUpdate(int node, int start, int end, int left, int right, int mod) {
                if (right < start || end < left) return;
                if (tree[node].mxx < mod) return; // no point if the largest element cannot be modded
                if (start == end) {
                        tree[node].sum %= mod;
                        tree[node].mxx %= mod;
                        return;
                }
                int mid = start + (end - start) / 2;
                rangeUpdate(2 * node, start, mid, left, right, mod);
                rangeUpdate(2 * node + 1, mid + 1, end, left, right, mod);
                tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        void pointUpdate(int node, int start, int end, int idx, int val) {
                if (start == end) {
                        tree[node] = Node(val, val);
                        return;
                }
                int mid = start + (end - start) / 2;
                if (idx <= mid) {
                        pointUpdate(2 * node, start, mid, idx, val);
                } else {
                        pointUpdate(2 * node + 1, mid + 1, end, idx, val);
                }
                tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        SegTree(int sz, vector<int> &a) {
                n = sz;
                tree.resize(4 * n, Node(0, -inf));
                build(1, 0, n - 1, a);
        }
        int query(int left, int right) {
                Node q = query(1, 0, n - 1, left, right);
                return q.sum;
        }
        void rangeUpdate(int left, int right, int mod) {
                rangeUpdate(1, 0, n - 1, left, right, mod);
        }
        void pointUpdate(int idx, int val) {
                pointUpdate(1, 0, n - 1, idx, val);
        }
};

void solve( ) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        SegTree segtree(n, a);

        while (m--) {
                int t;
                cin >> t;
                if (t == 1) { // sum from l to r
                        int l, r;
                        cin >> l >> r;
                        l--, r--;
                        int sum = segtree.query(l, r);
                        cout << sum << endl;
                } else if (t == 2) { // mod all vals from l to r
                        int l, r, x;
                        cin >> l >> r >> x;
                        l--, r--;
                        segtree.rangeUpdate(l, r, x);
                } else { // set a[k] = x
                        int k, x;
                        cin >> k >> x;
                        k--;
                        segtree.pointUpdate(k, x);
                }
        }
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        // cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
