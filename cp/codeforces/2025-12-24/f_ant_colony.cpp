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

const int inf = 1e9 + 1;

struct Node {
        int mn, gcd;
};

class Segtree {
      public:
        int n;
        vector<Node> tree;

        Node merge(Node &a, Node &b) {
                int mnn = min(a.mn, b.mn);
                int gcdd = __gcd(a.gcd, b.gcd);
                return {mnn, gcdd};
        }

        void build(int node, int start, int end, vector<int> &a) {
                if (start == end) {
                        tree[node] = {a[start], a[start]};
                        return;
                }
                int mid = start + (end - start) / 2;
                build(2 * node, start, mid, a);
                build(2 * node + 1, mid + 1, end, a);
                tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        Node query(int node, int start, int end, int left, int right) {
                if (right < start || end < left) return {inf, 0};
                if (left <= start && end <= right) return tree[node];
                int mid = start + (end - start) / 2;
                Node p1 = query(2 * node, start, mid, left, right);
                Node p2 = query(2 * node + 1, mid + 1, end, left, right);
                return merge(p1, p2);
        }

        Segtree(int sz, vector<int> &a) {
                n = sz;
                tree.resize(4 * n);
                build(1, 0, n - 1, a);
        }

        Node query(int left, int right) {
                return query(1, 0, n - 1, left, right);
        }
};

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        Segtree segtree(n, a);
        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[a[i]].push_back(i);

        // all pairs in [l, r] fight
        // s[i]++ if s[i] % s[j] == 0
        // s[j]++ if s[j] % s[i] == 0
        // ant saved iff s[i] == (r - l) or it got 1 point in each pair up (like GCD)

        auto count = [&](int l, int r) -> int {
                int len = r - l + 1;
                Node res = segtree.query(l, r);

                int mnn = res.mn;
                int gcdd = res.gcd;
                if (mnn != gcdd) return len;

                vector<int> poss = pos[mnn];
                auto ub = upper_bound(poss.begin( ), poss.end( ), r);
                auto lb = lower_bound(poss.begin( ), poss.end( ), l);

                int cnt = ub - lb;
                return len - cnt;
        };

        int q;
        cin >> q;
        while (q--) {
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << count(l, r) << endl;
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
