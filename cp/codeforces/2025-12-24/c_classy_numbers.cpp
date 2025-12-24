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

void solve( ) {
        int l, r;
        cin >> l >> r;
        int nzLimit = 3;

        auto dfs = [&](auto &&go, const string &strx, int idx, int nzCnt, bool bounded, vector<vector<vector<int>>> &dp) -> int {
                if (idx == strx.size( )) return 1;
                if (dp[idx][nzCnt][bounded] != -1) return dp[idx][nzCnt][bounded];

                // bounded = true -> can go up to strx[idx]
                // bounded = false -> can go up to 9 (when we selected a smaller digit before)

                int upp = strx[idx] - '0';
                int limit = bounded ? upp : 9;
                int cnt = 0;

                for (int dig = 0; dig <= limit; dig++) {
                        int newNzCnt = nzCnt + (dig != 0);
                        if (newNzCnt > 3) continue;
                        cnt += go(go, strx, idx + 1, newNzCnt, bounded && (dig == limit), dp);
                }

                return dp[idx][nzCnt][bounded] = cnt;
        };

        auto cntUpto = [&](int x) -> int {
                string strx = to_string(x);
                vector<vector<vector<int>>> dp(strx.size( ), vector<vector<int>>(nzLimit + 1, vector<int>(2, -1)));
                return dfs(dfs, strx, 0, 0, true, dp);
        };

        cout << cntUpto(r) - cntUpto(l - 1) << endl;
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
