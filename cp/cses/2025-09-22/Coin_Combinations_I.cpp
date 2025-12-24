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
const int mod = 1e9 + 7;

void solve( ) {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &i : coins) cin >> i;

    vector<int> dp(x + 1, 0); // ways
    dp[0] = 1;

    for (int i = 1; i <= x; i++) { // sum
        for (int c : coins) {      // coins
            if (i - c >= 0) {      // valid
                dp[i] = (dp[i] + dp[i - c]) % mod;
            }
        }
    }

    cout << dp[x] << endl;
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