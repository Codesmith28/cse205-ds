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

void solve( ) {
    int w, h, k;
    cin >> w >> h >> k;

    int a1 = 0, a2 = 0;
    int res = 0;
    for (int i = 0; i < k; i++) {
        a1 = w * h;
        w -= 2, h -= 2;
        a2 = w * h;
        w -= 2, h -= 2;
        res += a1 - a2;
    }

    cout << res << endl;
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