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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    // states : 0 -> rest, 1 -> contest, 2 -> gym
    vector<vector<int>> memo(n + 1, vector<int>(3, INT_MAX));
    for (int i = 0; i < 3; i++) memo[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        memo[i][0] = 1 + min({memo[i - 1][0], memo[i - 1][1], memo[i - 1][2]});               // Rest on rest day
        if (a[i - 1] == 1 || a[i - 1] == 3) memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]); // Rest on contest day
        if (a[i - 1] == 2 || a[i - 1] == 3) memo[i][2] = min(memo[i - 1][0], memo[i - 1][1]); // Rest on gym day
    }

    cout << min({memo[n][0], memo[n][1], memo[n][2]}) << endl;
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
