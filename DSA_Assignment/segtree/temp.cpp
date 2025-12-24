#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct segtree {
    vector<int> tree, lazy;
    int n;

    segtree(int sz) {
        int n = sz;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

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

    int query(int node, int st, int en, int left, int right) {
        // check for pending updates:
        if (lazy[node] != 0) {
            tree[node] += (en - st + 1) * lazy[node];
            if (st != en) {
                // propagate the changes:
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // normal range query:
        if (right < st || en < left) return 0;            // none
        if (left <= st && en <= right) return tree[node]; // complete
        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, mid, left, right);
        int h2 = query(2 * node + 1, mid + 1, en, left, right);
        // based on operation:
        return h1 + h2;
    }

    void rng_update(int node, int st, int en, int left, int right, int val) {
        if (lazy[node] != 0) {
            tree[node] = (en - st + 1) * lazy[node];
            if (st != en) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // range update:
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
        rng_update(2 * node, st, mid, left, right, val);
        rng_update(2 * node + 1, mid + 1, en, left, right, val);
        // based on operation:
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void pt_update(int node, int st, int en, int idx, int val) {
        rng_update(node, st, en, idx, idx, val);
    }
};

int main( ) {
    int sz = 1;

    return 0;
}