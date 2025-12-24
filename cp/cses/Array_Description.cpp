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

void solve( ) {
    int n, lim;
    cin >> n >> lim;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<vector<int>> memo(n + 1, vector<int>(lim + 1, 0));

    // Base case
    for (int curr = 1; curr <= lim; curr++) {
        if (a[0] == 0 || a[0] == curr) {
            memo[0][curr] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int curr = 1; curr <= lim; curr++) {
            if (a[i] != 0 && a[i] != curr) {
                memo[i][curr] = 0;
                continue;
            }
            for (int prev = curr - 1; prev <= curr + 1; prev++) {
                if (prev >= 1 && prev <= lim) {
                    memo[i][curr] = (memo[i][curr] + memo[i - 1][prev]) % mod;
                }
            }
        }
    }

    dbg(memo);

    int res = 0;
    for (int curr = 1; curr <= lim; curr++) res = (res + memo[n - 1][curr]) % mod;
    cout << res << endl;
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
