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
int mod = 998244353;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    for (int k = n; k >= 1; k--) {
        multiset<int> st(a.begin( ), a.end( ));

        for (int i = 0; i < k; i++) {
            auto it = st.upper_bound(k - i);
            if (it == st.begin( )) break;
            it--;
            st.erase(it);

            // add k - i + 1 to the first element
            if (!st.empty( )) {
                int x = *st.begin( );
                st.erase(st.begin( ));
                st.insert(x + k - i + 1);
            }
        }

        if (st.size( ) + k == n) {
            cout << k << endl;
            return;
        }
    }

    cout << 0 << endl;
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
