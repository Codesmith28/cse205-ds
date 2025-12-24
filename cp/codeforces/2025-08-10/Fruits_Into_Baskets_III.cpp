#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

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
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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

        if (right < st || en < left) return 0;
        if (left <= st && en <= right) return tree[node];

        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        return max(h1, h2);
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
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
};

class Solution {
  public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        int n = baskets.size( );
        segtree seg(n);

        // binary search on the best possible basket using segment tree:
        auto first_larger = [&](auto &&go, int node, int st, int en, int val) -> int {
            if (seg.tree[node] < val) return n;
            if (st == en) return st;
            int mid = st + (en - st) / 2;
            if (seg.tree[2 * node] >= val) {
                return go(go, 2 * node, st, mid, val);
            } else {
                return go(go, 2 * node + 1, mid + 1, en, val);
            }
        };

        int cnt = 0;
        for (int x : fruits) {
            int pos = first_larger(first_larger, 1, 0, n - 1, x);
            if (pos == n) {
                cnt++;
            } else {
                seg.pt_update(1, 0, n - 1, pos, 0); // basket cap = 0;
            }
        }
        return cnt;
    }
};

int main( ) {
    vector<vector<int>> fruits = {
        {4, 2, 5},
        {3, 6, 1}
    };
    vector<vector<int>> baskets = {
        {3, 5, 4},
        {6, 4, 7}
    };
    Solution sol;
    for (int i = 0; i < fruits.size( ); i++) {
        cout << sol.numOfUnplacedFruits(fruits[i], baskets[i]) << endl;
    }
    return 0;
}