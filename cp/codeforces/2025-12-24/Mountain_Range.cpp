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
        vector<int> heights(n);
        for (int &i : heights) cin >> i;

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                        if (heights[j] > heights[i]) {
                                dp[i] = max(dp[i], dp[j] + 1);
                        }
                }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
                ans = max(ans, dp[i]);
        }
        cout << ans << endl;
}

int32_t main( ) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int test_cases = 1;
        // cin >> test_cases;

        while (test_cases--) {
                solve( );
        }

        return 0;
}
