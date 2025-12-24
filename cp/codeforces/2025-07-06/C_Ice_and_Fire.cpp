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
    string s;
    cin >> s;

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n - 1; i++) {
        int prev = s[i - 1];
        int curr = s[i];
        if (prev == curr) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = i + 1;
        }
    }

    for (int i = 0; i < n - 1; i++) cout << dp[i] << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}