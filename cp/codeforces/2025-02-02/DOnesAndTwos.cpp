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
int mod = 1e9 + 7;

void solve( ) {
    int n, q;
    cin >> n >> q;
    vector<int> w(n);
    for (int &i : w) cin >> i;

    set<int> oidx, tidx;
    for (int i = 0; i < n; i++) w[i] == 1 ? oidx.insert(i) : tidx.insert(i);

    auto mx_sum = [&](int p) -> int {
        int mx = oidx.size( ) + 2 * tidx.size( );
        if (oidx.size( ) % 2 == p) return mx;
        if (oidx.empty( ) && p == 1) return 0;

        int f1 = *oidx.begin( );
        int l1 = *oidx.rbegin( );
        int lower = f1 * 2 + 1;
        int upper = (n - l1 - 1) * 2 + 1;
        return mx - min(lower, upper);
    };

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int a;
            cin >> a;
            int p = a % 2;
            dbg(mx_sum(p), a);
            cout << (a <= mx_sum(p) ? "YES" : "NO") << endl;
        } else {
            int idx, val;
            cin >> idx >> val;
            idx--;

            int old = w[idx];
            if (old == val) continue;

            if (old == 2 && val == 1) {
                oidx.insert(idx);
                tidx.erase(idx);
            }
            if (old == 1 && val == 2) {
                oidx.erase(idx);
                tidx.insert(idx);
            }

            w[idx] = val;
        }
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve( );
    }

    return 0;
}
