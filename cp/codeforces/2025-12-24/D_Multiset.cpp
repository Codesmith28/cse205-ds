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
using ordered_set = tree<T,                                  // key type
                         null_type,                          // mapped type; null_type → like `set`, not `map`
                         std::less<T>,                       // comparator
                         rb_tree_tag,                        // red-black tree (also supports splay trees etc.)
                         tree_order_statistics_node_update>; // adds order-statistics operations

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;

void solve( ) {
        int n, q;
        cin >> n >> q;
        ordered_set<pii> ost;
        for (int i = 0; i < n; i++) {
                int a;
                cin >> a;
                ost.insert({a, i});
        }

        for (int i = 0; i < q; i++) {
                int k;
                cin >> k;
                if (k < 0) {
                        // remove the kth element from the multiset
                        k = abs(k);
                        auto it = ost.find_by_order(k - 1);
                        if (it != ost.end( )) ost.erase(it);
                } else {
                        // put k in the multiset
                        ost.insert({k, n + i});
                }
        }

        if (ost.size( ) == 0) {
                cout << 0 << endl;
        } else {
                cout << ost.begin( )->first << endl;
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