#include <bits/stdc++.h>
#include <sstream>
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

class SegTree {
      public:
        int n;
        vector<int> tree, lazy;

        void build(int node, int start, int end, vector<int> &a) {
                if (start == end) {
                        tree[node] = a[start];
                        return;
                }
                int mid = (start + end) / 2;
                build(node * 2, start, mid, a);
                build(node * 2 + 1, mid + 1, end, a);
                tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }

        void push(int node, int start, int end) {
                if (lazy[node] != 0) {
                        tree[node] += lazy[node];
                        if (start != end) {
                                lazy[node * 2] += lazy[node];
                                lazy[node * 2 + 1] += lazy[node];
                        }
                        lazy[node] = 0;
                }
        }

        int query(int node, int start, int end, int left, int right) {
                push(node, start, end);
                if (right < start || end < left) return inf;
                if (left <= start && end <= right) return tree[node];
                int mid = (start + end) / 2;
                int q1 = query(node * 2, start, mid, left, right);
                int q2 = query(node * 2 + 1, mid + 1, end, left, right);
                return min(q1, q2);
        }

        void rangeUpdate(int node, int start, int end, int left, int right, int val) {
                push(node, start, end);
                if (right < start || end < left) return;
                if (left <= start && end <= right) {
                        tree[node] += val;
                        if (start != end) {
                                lazy[node * 2] += val;
                                lazy[node * 2 + 1] += val;
                        }
                        return;
                }
                int mid = (start + end) / 2;
                rangeUpdate(node * 2, start, mid, left, right, val);
                rangeUpdate(node * 2 + 1, mid + 1, end, left, right, val);
                tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }

        SegTree(int sz, vector<int> &a) {
                n = sz;
                tree.assign(4 * n, 0);
                lazy.assign(4 * n, 0);
                build(1, 0, n - 1, a);
        }
        int query(int left, int right) {
                if (left <= right) {
                        return query(1, 0, n - 1, left, right);
                } else {
                        int q1 = query(1, 0, n - 1, left, n - 1);
                        int q2 = query(1, 0, n - 1, 0, right);
                        return min(q1, q2);
                }
        }
        void rangeUpdate(int left, int right, int val) {
                if (left <= right) {
                        rangeUpdate(1, 0, n - 1, left, right, val);
                } else {
                        rangeUpdate(1, 0, n - 1, left, n - 1, val);
                        rangeUpdate(1, 0, n - 1, 0, right, val);
                }
        }
};

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        for (int i = 0; i < n; i++) a.push_back(a[i]);

        SegTree segtree(2 * n, a);

        int m;
        cin >> m;

        while (m--) {
                string s;
                getline(cin, s);
                if (s.empty( )) {
                        m++;
                        continue;
                }

                stringstream ss(s);
                int lf, rg, v;
                if (ss >> lf >> rg) {
                        if (ss >> v) {
                                segtree.rangeUpdate(lf, rg, v);
                        } else {
                                cout << segtree.query(lf, rg) << endl;
                        }
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
