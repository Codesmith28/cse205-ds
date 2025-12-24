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

const int inf = 1e18;
const int ninf = -1 * inf;

int mod = 1e9 + 7;

void solve( ) {
    int n, k;
    cin >> n >> k;

    // n -> tc
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        // a -> red
        // b -> white: to be eaten in grps of k only
        // total ways to be eaten % mod

        vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= a; i++) dp[i][0] = 1;

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (i >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j >= k) dp[i][j] = (dp[i][j] + dp[i][j - k]) % mod;
            }
        }

        cout << dp[a][b] << endl;
    }
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