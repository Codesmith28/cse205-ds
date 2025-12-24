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

const int inf = 5e2 + 1;

void solve( ) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        auto recur = [&](auto &&go, int l, int r) -> int {
                if (l > r) return 0;
                if (l == r) return 1;
                if (dp[l][r] != -1) return dp[l][r];

                // split from curr char = s[l]
                int res = 1 + go(go, l + 1, r);
                for (int i = l + 1; i <= r; i++) {
                        if (s[i] == s[l]) {
                                res = min(res, go(go, l + 1, i - 1) + go(go, i, r));
                        }
                }

                return dp[l][r] = res;
        };

        cout << recur(recur, 0, n - 1) << endl;
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
