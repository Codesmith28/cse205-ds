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
    int n;
    cin >> n;

    int sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    int target = sum / 2;
    vector<vector<int>> memo(n + 1, vector<int>(target + 1, 0));

    memo[0][0] = 1;
    for (int num = 1; num <= n; num++) {
        for (int sum = 1; sum <= target; sum++) {
            int not_take = memo[num - 1][sum];
            int take = (sum - num >= 0) ? memo[num - 1][sum - num] : 0;
            memo[num][sum] = (not_take + take) % mod;
        }
    }

    cout << memo[n][target] << endl;
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