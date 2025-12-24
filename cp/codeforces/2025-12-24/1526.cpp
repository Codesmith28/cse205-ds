#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

/// Segment tree snippet
class SegTree {
  private:
    int n;
    vector<int> tree, lazy, &arr;

    // build the segment tree
    void build(int node, int st, int en) {
        if (st == en) {
            tree[node] = arr[st];
        } else {
            int mid = st + (en - st) / 2;
            build(2 * node, st, mid);
            build(2 * node + 1, mid + 1, en);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // apply and propagate lazy value
    void push(int node, int st, int en) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (st != en) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    // query max in range [left, right]
    int query(int node, int st, int en, int left, int right) {
        push(node, st, en);

        if (right < st || en < left) return INT_MAX;
        if (left <= st && en <= right) return tree[node];

        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        return min(h1, h2);
    }

    // Add 'val' to elements in range [left, right]
    void rangeUpdate(int node, int st, int en, int left, int right, int val) {
        push(node, st, en);

        if (right < st || en < left) return;

        if (left <= st && en <= right) {
            tree[node] += val;
            if (st != en) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = st + (en - st) / 2;
        rangeUpdate(2 * node, st, mid, left, right, val);
        rangeUpdate(2 * node + 1, mid + 1, en, left, right, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    // Set arr[idx] = val (0-based)
    void pointUpdate(int node, int st, int en, int idx, int val) {
        push(node, st, en);

        if (st == en) {
            tree[node] = val;
            return;
        }

        int mid = st + (en - st) / 2;
        if (idx <= mid)
            pointUpdate(2 * node, st, mid, idx, val);
        else
            pointUpdate(2 * node + 1, mid + 1, en, idx, val);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

  public:
    SegTree(int sz, vector<int> &arr) : arr(arr) {
        n = sz;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
    void rangeUpdate(int left, int right, int val) {
        rangeUpdate(1, 0, n - 1, left, right, val);
    }
    void pointUpdate(int idx, int val) {
        pointUpdate(1, 0, n - 1, idx, val);
    }
};

class Solution {
  public:
    int minNumberOperations(vector<int> &target) {
        int n = target.size( );
        SegTree st(n, target);

        int l = 0, r = n - 1;
        int ops = 0;
        int prevMn = 0;
        while (l <= r) {
            int currMn = st.query(l, r);
            if (currMn > 0 && prevMn != currMn) ops++;
            prevMn = currMn;

            int mn1 = st.query(l + 1, r);
            int mn2 = st.query(l, r - 1);

            if (mn1 > currMn) {
                l++;
            } else if (mn2 > currMn) {
                r--;
            } else {
                l++, r--;
            }
        }

        return ops;
    }
};

// [1,2,3,2,1]
// [3,1,1,2]
// [3,1,5,4,2]

int main( ) {
    vector<vector<int>> target = {
        {1, 2, 3, 2, 1},
        {3, 1, 1, 2},
        {3, 1, 5, 4, 2},
    };
    Solution sol;
    for (auto &t : target) {
        cout << sol.minNumberOperations(t) << "\n";
    }
    return 0;
}