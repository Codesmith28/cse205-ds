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

    a = "#" + a;
    b = "#" + b;

    int n = a.size( ), m = b.size( );
    vector<vector<int>> memo(n, vector<int>(m, 0));

    // base case
    for (int i = 0; i < n; i++) memo[i][0] = i;
    for (int i = 0; i < m; i++) memo[0][i] = i;

    // to construct the answer upto index i, j
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i] == b[j]) {
                memo[i][j] = memo[i - 1][j - 1];
            } else {
                memo[i][j] = 1 + min({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]});
            }
        }
    }

    cout << memo[n - 1][m - 1] << endl;
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
