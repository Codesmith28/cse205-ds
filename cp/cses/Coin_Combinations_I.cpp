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
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &i : coins) cin >> i;
    sort(coins.begin( ), coins.end( ));

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % (int)(1e9 + 7);
            }
        }
    }

    cout << dp[x] << endl;
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