/*
You are given an array that displays the outcome of a coin toss
0 means heads
1 means tails

you are to answer q queries
queries are of two types
type 1 give number of tails between l and r
type 2 flip all the outcome from l to r

print the number of tails after each query of type 1
update the array after each query of type 2 and print the array after each query of type 2
*/

#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

/*
    t[] -> segTree array
    v -> idx in segTree
    tl , tr -> range of segTree
*/

class SegTree {
  public:
    int len;
    vector<int> t;

    SegTree() {
    }

    SegTree(int l) {
        len = l;
        t.resize(4 * len);
    }

    // Build Segment Tree -- build(a, 1, 0, len-1);
    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    // Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
    int query(int v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0; // no overlap

        if (l <= tl && tr <= r) return t[v]; // Full overlap

        // Partial Overlap
        int tm = (tl + tr) / 2;
        int leftAns = query(2 * v, tl, tm, l, r);
        int rightAns = query(2 * v + 1, tm + 1, tr, l, r);

        return leftAns + rightAns;
    }

    // Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, id, val)
    void update(int v, int tl, int tr, int id, int val) {
        // reached leaf node
        if (tl == id && tr == id) {
            t[v] = val;
            return;
        }
        if (id > tr || id < tl) return;

        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, id, val);
        update(2 * v + 1, tm + 1, tr, id, val);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    // over-ridden functions
    void build(vector<int> &a) {
        build(a, 1, 0, len - 1);
    }

    int query(int l, int r) {
        return query(1, 0, len - 1, l, r);
    }

    void update(int id, int val) {
        update(1, 0, len - 1, id, val);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int m;
    cin >> m;
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
    }
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}