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

int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto &i : grid) {
        for (auto &j : i) cin >> j;
    }

    vector<int> dir = {0, 1, 1, 0};
    vector<vector<bool>> vis(n, vector<bool>(n));

    vector<vector<int>> memo(n, vector<int>(n, 0));
    memo[0][0] = (grid[0][0] == '*' ? 0 : 1);

    // dp to find the numeber of ways to reach the cell [i][j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                memo[i][j] = 0;
            } else {
                int up = 0, left = 0;
                if (i > 0) up = (up + memo[i - 1][j]) % mod;
                if (j > 0) left = (left + memo[i][j - 1]) % mod;
                memo[i][j] = (memo[i][j] + up + left) % mod;
            }
        }
    }

    cout << memo[n - 1][n - 1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}