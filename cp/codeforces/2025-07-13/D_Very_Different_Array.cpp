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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(a.begin( ), a.end( ));
    sort(b.rbegin( ), b.rend( ));

    vector<int> c(n);
    int diff = 0;

    for (int i = 0; i < n; i++) {
        c[i] = b[m - n + i];
        diff += abs(c[i] - a[i]);
    }

    int res = diff;

    for (int i = 0; i < n; i++) {
        diff -= abs(c[i] - a[i]);
        c[i] = b[i];
        diff += abs(c[i] - a[i]);
        res = max(res, diff);
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