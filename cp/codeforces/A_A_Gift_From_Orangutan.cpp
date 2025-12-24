#include <bits/stdc++.h>
#include <iostream>
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin( ), a.end( ));

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    swap(a[0], a[n - 1]);
    int bmn = a[n - 1], cmx = a[0];
    int res = 0;

    for (int i = 1; i < n; i++) {
        bmn = min(bmn, a[i]);
        cmx = max(cmx, a[i]);
        res += (cmx - bmn);
    }

    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}