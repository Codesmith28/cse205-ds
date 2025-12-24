#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,                                // key type
                         null_type,                        // mapped type; null_type → like `set`, not `map`
                         std::less<T>,                     // comparator
                         rb_tree_tag,                      // red-black tree (also supports splay trees etc.)
                         tree_order_statistics_node_update // adds order-statistics operations
                         >;

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, m;
    cin >> n >> m;

    ordered_set<pii> os;
    map<int, int> sal;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        os.insert({x, i});
        sal[i] = x;
    }

    while (m--) {
        char t;
        cin >> t;
        if (t == '!') {
            // Update: Employee k salary becomes x
            int k, x;
            cin >> k >> x;
            int prev = sal[k];
            os.erase({prev, k});
            os.insert({x, k});
            sal[k] = x;
        } else if (t == '?') {
            // Query: Count salaries in range [a, b]
            int a, b;
            cin >> a >> b;
            int cnt_a = os.order_of_key({a, 0});
            int cnt_b = os.order_of_key({b + 1, 0});
            cout << cnt_b - cnt_a << endl;
        }
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
