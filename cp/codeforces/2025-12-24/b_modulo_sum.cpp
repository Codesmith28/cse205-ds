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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        // to check if any subseq sum is divisible by m

        if (n >= m) { // m - 1 poss remainders
                cout << "YES" << endl;
                return;
        }

        vector<bool> dp(m, false); // dp[i] = remainder = i;
        for (int i : a) {
                int modi = i % m;
                vector<bool> nxtDp = dp;
                nxtDp[modi] = true;
                for (int r = 0; r < m; r++) { // for all rems 'r' poss we can also make ('r' + modi) % m
                        if (dp[r]) {
                                nxtDp[(r + modi) % m] = true;
                        }
                }
                dp.swap(nxtDp);
                if (dp[0]) {
                        cout << "YES" << endl;
                        return;
                }
        }

        cout << (dp[0] ? "YES" : "NO") << endl;
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
