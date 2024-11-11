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
    string a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);
    int n = a.size( );
    int m = b.size( );

    int diff = m - n;
    for (int i = 0; i < diff; i++) a = '0' + a;

    vector<vector<int>> memo(m + 1, vector<int>(10, 0));

    for (int d = 0; d < 10; d++) {
        if (d >= (a[0] - '0') && d <= (b[0] - '0')) memo[1][d] = 1;
    }

    for (int len = 1; len <= m; len++) {
        for (int d = 0; d < 10; d++) {
            if (d >= (a[len] - '0') && d <= (b[len] - '0')) {
                for (int prev = 0; prev < 10; prev++) {
                    memo[len][d] += memo[len - 1][prev];
                }
            }
        }
    }

    int ans = 1;
    for (int len = 1; len <= m; len++) {
        int curr = 0;
        for (int d = 1; d < 10; d++) {
            curr += memo[len][d];
        }
        if (curr) ans *= curr;
    }

    cout << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    /*cin >> testCases;*/

    while (testCases--) {
        solve( );
    }

    return 0;
}
