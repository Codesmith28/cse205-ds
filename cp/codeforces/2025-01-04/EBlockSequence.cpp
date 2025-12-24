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
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> dp(n, 0);

    auto get = [&](int x) -> int {
        x++;
        if (x > n) {
            return n + 1;
        } else if (x == n) {
            return 0;
        }
        return dp[x];
    };

    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = dp[i + 1] + 1;
        dp[i] = min(dp[i], get(i + a[i]));
    }

    cout << dp[0] << endl;
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
