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

const int inf = 1e18;

#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegTree {
      public:
        int n;
        vector<int> tree;

        SegTree(int size) {
                n = size;
                tree.resize(4 * n, 0);
        }

        void update(int node, int start, int end, int idx, int val) {
                if (start == end) {
                        tree[node] += val;
                        return;
                }
                int mid = start + (end - start) / 2;
                if (idx <= mid) {
                        update(2 * node, start, mid, idx, val);
                } else {
                        update(2 * node + 1, mid + 1, end, idx, val);
                }
                tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        void update(int idx, int val) {
                update(1, 0, n - 1, idx, val);
        }

        int query(int node, int start, int end, int left, int right) {
                if (right < start || left > end) return 0;
                if (left <= start && end <= right) return tree[node];
                int mid = start + (end - start) / 2;
                int q1 = query(2 * node, start, mid, left, right);
                int q2 = query(2 * node + 1, mid + 1, end, left, right);
                return q1 + q2;
        }
        int query(int left, int right) {
                return query(1, 0, n - 1, left, right);
        }
};

void solve( ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        // compression
        vector<int> vals = a;
        sort(vals.begin( ), vals.end( ));
        vals.erase(unique(vals.begin( ), vals.end( )), vals.end( ));
        auto getID = [&](int x) -> int {
                return (int)(lower_bound(vals.begin( ), vals.end( ), x) - vals.begin( ));
        };

        int m = vals.size( );

        vector<int> smaller(n, 0), bigger(n, 0);
        SegTree st1(m), st2(m);

        for (int i = 0; i < n; i++) {
                int id = getID(a[i]);
                bigger[i] = st2.query(id + 1, m - 1);
                st2.update(id, 1);
        }
        for (int i = n - 1; i >= 0; i--) {
                int id = getID(a[i]);
                smaller[i] = st1.query(0, id - 1);
                st1.update(id, 1);
        }

        int res = 0;
        for (int i = 0; i < n; i++) res += smaller[i] * bigger[i];
        cout << res << endl;
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
