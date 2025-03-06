#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;

void solve( ) {
    int n, k, p;
    cin >> n >> k >> p;

    if (k > n * p || k < -n * p) {
        cout << -1 << endl;
        return;
    }

    int ops = (abs(k) + p - 1) / p;
    cout << ops << endl;
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
