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
    int n, sum;
    cin >> n >> sum;
    vector<int> coin(n);
    for (int &i : coin) cin >> i;

    vector<int> memo(sum + 1);
    memo[0] = 1;

    for (int c : coin) {
        for (int curr = c; curr <= sum; curr++) {
            memo[curr] = (memo[curr] + memo[curr - c]) % mod;
        }
    }

    cout << memo[sum] << endl;
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
