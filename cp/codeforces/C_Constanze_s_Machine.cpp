#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> dp(1e6, 0);

    for (char c : s) {
        if (c == 'm' or c == 'w') {
            cout << 0 << endl;
            return;
        }
    }

    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s.substr(i - 2, 2) == "uu" or s.substr(i - 2, 2) == "nn") {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[n] % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}