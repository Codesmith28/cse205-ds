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
    int n;
    cin >> n;

    map<int, int> x, y, d1, d2;

    for (int i = 0; i < n; i++) {
        int xc, yc;
        cin >> xc >> yc;
        x[xc]++;
        y[yc]++;
        d1[xc + yc]++;
        d2[xc - yc]++;
    }

    int ans = 0;
    for (auto [k, v] : x) ans += v * (v - 1);
    for (auto [k, v] : y) ans += v * (v - 1);
    for (auto [k, v] : d1) ans += v * (v - 1);
    for (auto [k, v] : d2) ans += v * (v - 1);

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
