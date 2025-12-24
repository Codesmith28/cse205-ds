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
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto &it : grid)
        for (auto &i : it) cin >> i;

    vector<int> dir = {0, 1, 1, 0};
    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[0][0] = (grid[0][0] == '*' ? 0 : 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                int up, left;
                if (i > 0) up = (up + dp[i - 1][j] + 1) % mod;
                if (j > 0) left = (left + dp[i][j - 1]) % mod;
                dp[i][j] = (up + left + dp[i][j]) % mod;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
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