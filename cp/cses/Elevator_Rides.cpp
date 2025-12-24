#include <bits/stdc++.h>
#include <vector>
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
    int n, lim;
    cin >> n >> lim;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    /*pii -> number of elevators, wt in the last elevator*/

    int subset_cnt = 1 << n;
    vector<pii> memo(subset_cnt);
    memo[0] = {1, 0}; // 1 elevator, 0 wt

    for (int curr_set = 1; curr_set < subset_cnt; curr_set++) {
        pii base = {INT_MAX, INT_MAX};
        for (int i = 0; i < n; i++) {
            if (curr_set & (1 << i)) {
                pii prev = memo[curr_set ^ (1 << i)];
                if (prev.second + a[i] <= lim) {
                    base = min(base, {prev.first, prev.second + a[i]});
                } else {
                    base = min(base, {prev.first + 1, a[i]});
                }
            }
        }
        memo[curr_set] = base;
    }

    cout << memo[subset_cnt - 1].first << endl;
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
