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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int &i : p) cin >> i;

        // winning idx: indices such that only 1 move can be made from there
        // other wins: which can lead to a winnnig idx

        vector<bool> dp(n, false);
        int mn = inf, mnWin = inf; // smallest poss value from which a move can definitely be made

        for (int i = 0; i < n; i++) {
                int curr = p[i];
                if (mn < curr && curr < mnWin) {
                        // curr can go to prev winning pos and not any further than that
                        dp[i] = true;
                        mnWin = curr;
                }
                mn = min(mn, curr);
        }

        int cnt = 0;
        for (bool i : dp) cnt += i;
        cout << cnt << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int testCases = 1;
        cin >> testCases;

        while (testCases--) {
                solve( );
        }

        return 0;
}
