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

const int inf = 1e4;
const int ninf = -1 * inf;

/*
1 2 1
    -> [1 2 1] => ans = 1
1 2 3
    -> [1] 2 3
    -> [2] 3
    -> [3] => ans = 3
1 4 4 2 3 2 1
    -> 1 [4 4] 2 3 2 1
    -> [1 2 3 2 1] => ans = 2
*/

// min moves to make string empty
// move -> remove a palindromic substring

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<vector<int>> dp(n, vector<int>(n, inf)); // min moves to delete segment [i, j]
    for (int i = 0; i < n; i++) dp[i][i] = 1;       // palindromic

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if (a[l] == a[r]) { // for palindromic construction
                if (len == 2) {
                    dp[l][r] = 1;
                } else {
                    dp[l][r] = dp[l + 1][r - 1];
                }
            }
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
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