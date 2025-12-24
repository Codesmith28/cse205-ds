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
const int ninf = -1 * inf;

struct BIT {
    int n;
    vector<int> tree;

    /// purely 0-based
    BIT(int size) {
        n = size;
        tree.assign(n, 0);
    }

    /// Add `val` to index `i` (0-based)
    void update(int i, int val) {
        while (i < n) {
            tree[i] += val;
            i |= (i + 1); // move to next index
        }
    }

    /// Prefix sum query: sum of elements in [0, i] (0-based)
    int query(int i) {
        int res = 0;
        while (i >= 0) {
            res += tree[i];
            i = (i & (i + 1)) - 1; // move to parent
        }
        return res;
    }

    /// Range sum query: sum of elements in [l, r] (0-based)
    int range_query(int l, int r) {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};

void solve( ) {
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
