#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

struct Node {
    int prod;
    vector<int> cnt;
};

struct segtree {
    int n, k;
    vector<Node> tree;

    // prod initialized with 1 and all rem_cnt set to 0
    segtree(int sz, int mod) {
        n = sz, k = mod;
        tree.resize(4 * n, {1, vector<int>(k, 0)});
    };

    // merge left and right nodes:
    void merge(Node &left, Node &right, Node &out) {
        out.prod = (1LL * left.prod * right.prod) % k;
        for (int i = 0; i < k; i++) out.cnt[i] = left.cnt[i];
        for (int i = 0; i < k; i++) {
            int new_mod = (1LL * left.prod * i) % k;
            out.cnt[new_mod] += right.cnt[i];
        }
    };

    void build(vector<int> &arr, int node, int st, int en) {
        if (st == en) {
            int val = arr[st] % k;
            tree[node].prod = val;
            tree[node].cnt[val]++;
        } else {
            int mid = st + (en - st) / 2;
            build(arr, 2 * node, st, mid);
            build(arr, 2 * node + 1, mid + 1, en);
            merge(tree[2 * node], tree[2 * node + 1], tree[node]);
        }
    }

    void pt_update(int node, int st, int en, int idx, int val) {
        if (st == en) {
            tree[node].cnt[tree[node].prod] = 0; // reset
            tree[node].prod = val % k;           // set
            tree[node].cnt[tree[node].prod]++;   // set
        } else {
            int mid = st + (en - st) / 2;
            if (idx <= mid) {
                pt_update(2 * node, st, mid, idx, val);
            } else {
                pt_update(2 * node + 1, mid + 1, en, idx, val);
            }
            merge(tree[2 * node], tree[2 * node + 1], tree[node]);
        }
    }

    Node query(int node, int st, int en, int left, int right) {
        if (right < st || en < left) {
            Node neut;
            neut.prod = 1;
            neut.cnt = vector<int>(k, 0);
            return neut;
        }
        if (left <= st && en <= right) {
            return tree[node];
        }
        int mid = st + (en - st) / 2;
        Node lnode = query(2 * node, st, mid, left, right);
        Node rnode = query(2 * node + 1, mid + 1, en, left, right);
        Node res;
        res.cnt = vector<int>(k, 0);
        merge(lnode, rnode, res);
        return res;
    }
};

class Solution {
  public:
    vector<int> resultArray(vector<int> &nums, int k, vector<vector<int>> &queries) {
        int n = nums.size( );
        segtree sg(n, k);
        sg.build(nums, 1, 0, n - 1);

        vector<int> rem;

        for (auto q : queries) {
            int idx = q[0], val = q[1], start = q[2], mod = q[3];
            sg.pt_update(1, 0, n - 1, idx, val);
            Node res = sg.query(1, 0, n - 1, start, n - 1); // remove [0, left) === query [left, n - 1]
            rem.push_back(res.cnt[mod]);
        }

        return rem;
    }
};

int main( ) {
    // [1,2,3,4,5]
    // 3
    // [[2,2,0,2],[3,3,3,0],[0,1,0,1]]
    // [1,2,4,8,16,32]
    // 4
    // [[0,2,0,2],[0,2,0,1]]
    // [1,1,2,1,1]
    // 2
    // [[2,1,0,1]]

    vector<vector<int>> nums = {
        {1, 2, 3, 4, 5},
        {1, 2, 4, 8, 16, 32},
        {1, 1, 2, 1, 1},
    };
    vector<int> k = {
        3,
        4,
        2,
    };
    vector<vector<vector<int>>> queries = {
        {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}},
        {{0, 2, 0, 2}, {0, 2, 0, 1}},
        {{2, 1, 0, 1}},
    };

    Solution sol;
    for (int i = 0; i < nums.size( ); i++) {
        vector<int> ans = sol.resultArray(nums[i], k[i], queries[i]);
        cout << "Result: ";
        for (auto &x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}