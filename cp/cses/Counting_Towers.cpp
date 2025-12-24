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
    int t;
    cin >> t;
    vector<int> n(t);
    for (int &i : n) cin >> i;
    int mx = *max_element(n.begin( ), n.end( ));

    vector<vector<int>> memo;
    memo.push_back({2, 1, 1, 1, 1});

    /*
        0 -> closed from top and of width 1 or 2
        1 -> open from top and of wdith 2
        2 -> first one closed and another one open from top
        3 -> first one open and another one closed from top
        4 -> both open from top
    */
    /*
        0 can be made on {0, 1} and {0, 2, 3, 4}
        1 can be made on {0, 1}
        2, 3, 4 can be made on {0, 2, 3, 4}
    */

    /*precompute:*/
    for (int row = 1; row <= mx; row++) {
        vector<int> curr(5);
        vector<int> prev = memo.back( );
        for (int state : {0, 1}) curr[state] = (curr[state] + prev[0] + prev[1]) % mod;
        for (int state : {0, 2, 3, 4}) curr[state] = (curr[state] + prev[0] + prev[2] + prev[3] + prev[4]) % mod;
        memo.push_back(curr);
    }

    // dbg(memo);
    for (int i : n) {
        cout << (memo[i - 1][0]) % mod << endl;
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    /*cin >> testCases;*/

    while (testCases--) {
        solve( );
    }

    return 0;
}
