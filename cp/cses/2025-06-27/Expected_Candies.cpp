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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(2, -1)));

    auto go = [&](auto &&go, int l, int r, bool flag) -> double {
        if (l > r) return 0;
        if (dp[l][r][flag] != -1) return dp[l][r][flag];

        double left, right;
        if (flag) {
            left = a[l] + go(go, l + 1, r, !flag);
            right = a[r] + go(go, l, r - 1, !flag);
        } else {
            left = go(go, l + 1, r, !flag);
            right = go(go, l, r - 1, !flag);
        }

        double result = (left + right) / 2.0;
        dp[l][r][flag] = result;
        return result;
    };

    cout << fixed << setprecision(15) << go(go, 0, n - 1, true) << endl;
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
