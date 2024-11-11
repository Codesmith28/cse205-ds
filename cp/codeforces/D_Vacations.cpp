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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    /*
     * 0 -> rest
     * 1 -> contest
     * 2 -> gym
     * */

    vector<vector<int>> dp(n, vector<int>(3, 1e9));
    dp[0][0] = 1; // 0idx, 0type
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    /*cin >> testCases;*/

    while (testCases--) {
        solve();
    }

    return 0;
}