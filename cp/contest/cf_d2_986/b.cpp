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
    int n, b, c;
    cin >> n >> b >> c;

    if (b == 0) {
        if (c >= n) {
            cout << n << endl;
        } else if (c == n - 1 || c == n - 2) {
            cout << n - 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    if (c >= n) {
        cout << n << endl;
    } else {
        // all numbers greater than n have to be replaced with mex
        // numbers greater than n:
        cout << n - max(0LL, 1 + (n - c - 1) / b) << endl;
    }
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
