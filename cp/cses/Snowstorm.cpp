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

void solve( ) {
    int n = 10;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int sum_a = (a[0] - 0), sum_b = (b[0] - 0);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) sum_a += (a[i] - a[i - 1]);
        if (b[i] > b[i - 1]) sum_b += (b[i] - b[i - 1]);
    }

    cout << (sum_a < sum_b ? 1 : 2) << endl;
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