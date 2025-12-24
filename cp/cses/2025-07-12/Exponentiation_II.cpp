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

int power(int a, int x, int mod) {
    if (a == 0 && x == 0) return 1;
    int res = 1;
    while (x) {
        if (x & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        x >>= 1;
    }
    return res;
}

void solve( ) {
    int a, b, c;
    cin >> a >> b >> c;
    int m = 1e9 + 7;
    int x = power(b, c, m - 1);
    int ans = power(a, x, m);
    cout << ans << endl;
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