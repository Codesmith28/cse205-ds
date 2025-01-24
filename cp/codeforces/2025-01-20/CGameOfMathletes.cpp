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
    int n, k;
    cin >> n >> k;
    multiset<int> a;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    int res = 0;
    while (!a.empty( )) {
        int x = *a.begin( );
        a.erase(a.begin( ));
        auto it = a.find(k - x);
        if (it != a.end( )) {
            res++;
            a.erase(it);
        }
    }

    cout << res << endl;
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
