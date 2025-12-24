#include <bits/stdc++.h>

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct segtree {
    vector<int> tree;
    vector<int> lazy;
    int n;

    segtree(int sz) {
        n = sz;
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
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int st, int en, int left, int right) {
        if (right < st || left > en) return 0;
        if (left <= st && en <= right) return tree[node];
        int mid = st + (en - st) / 2;
        int h1 = query(2 * node, st, en, left, mid);
        int h2 = query(2 * node + 1, st, en, mid + 1, right);
        return h1 + h2;
    }

    void update(int node, int st, int en, int idx, int val) {
        if (st == en) {
            tree[node] = val;
        } else {
            int mid = st + (en - st) / 2;
            if (idx <= mid) {
                update(2 * node, st, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, en, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
};

int main( ) {
    int sz = 1;

    return 0;
}