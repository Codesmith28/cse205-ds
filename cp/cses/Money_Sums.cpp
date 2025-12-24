#include <bits/stdc++.h>
#include <numeric>
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
    vector<int> x(n);
    for (int &i : x) cin >> i;

    // subset sum problem:
    int total_sum = accumulate(x.begin( ), x.end( ), 0LL);
    vector<vector<bool>> memo(n + 1, vector<bool>(total_sum + 1, false));

    for (int idx = 0; idx <= n; idx++) memo[idx][0] = true;
    for (int sum = 1; sum <= total_sum; sum++) memo[0][sum] = false;

    for (int idx = 1; idx <= n; idx++) {
        for (int sum = 1; sum <= total_sum; sum++) {
            if (sum < x[idx - 1]) {
                memo[idx][sum] = memo[idx - 1][sum];
            } else {
                bool not_take = memo[idx - 1][sum];
                bool take = memo[idx - 1][sum - x[idx - 1]];
                memo[idx][sum] = take | not_take;
            }
        }
    }

    set<int> res;
    for (int sum = 1; sum <= total_sum; sum++)
        if (memo[n][sum]) res.insert(sum);

    cout << res.size( ) << endl;
    for (int i : res) cout << i << " ";
    cout << endl;
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