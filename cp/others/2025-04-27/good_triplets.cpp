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

    // build the segtree
    void build(vector<int> &arr, int node, int st, int en) {
        if (st == en) {
            tree[node] = arr[st];
        } else {
            int mid = st + (en - st) / 2;
            build(arr, 2 * node, st, mid);
            build(arr, 2 * node + 1, mid + 1, en);
            // based on operation here:
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    // query for [l, r]:
    int query(int node, int st, int en, int left, int right) {
        // check for any pending updates:
        if (lazy[node] != 0) {
            tree[node] += (en - st + 1) * lazy[node];
            if (st != en) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // normal query:
        if (right < st || en < left) return 0;            // none
        if (left <= st && en <= right) return tree[node]; // complete
        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        // based on operation:
        return h1 + h2;
    }

    // range update for [l, r]:
    void rng_update(int node, int st, int en, int left, int right, int val) {
        // check for any pending updates:
        if (lazy[node] != 0) {
            tree[node] += (en - st + 1) * lazy[node];
            if (st != en) {
                // propagate the changes:
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // normal range update:
        if (right < st || en < left) return; // no overlap
        if (left <= st && en <= right) {     // complete overlap
            tree[node] += (en - st + 1) * val;
            if (st != en) {
                // propagate the changes:
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        // partial overlap
        int mid = st + (en - st) / 2;
        rng_update(2 * node, st, mid, left, right, val);
        rng_update(2 * node + 1, mid + 1, en, left, right, val);

        // based on operation:
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void pt_update(int node, int st, int en, int idx, int val) {
        rng_update(node, st, en, idx, idx, val);
    }
};

class Solution {
  public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
#define int long long
    }
};
#undef int

int main( ) {
    int sz = 1;
    vector<vector<int>> nums1, nums2;
    nums1 = {
        {2, 0, 1, 3},
        {4, 0, 1, 3, 2}
    };
    nums2 = {
        {0, 1, 2, 3},
        {4, 1, 0, 2, 3}
    };

    Solution sol;
    sz = nums2.size( );
    for (int i = 0; i < sz; i++) cout << sol.goodTriplets(nums1[i], nums2[i]) << endl;

    return 0;
}
