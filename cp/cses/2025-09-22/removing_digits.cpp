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

    vector<int> dp(n + 1, -1);
    auto go = [&](auto &&go, int curr) -> int {
        if (curr == 0) return 0;
        if (dp[curr] != -1) return dp[curr];

        string num = to_string(curr);
        int mx = *max_element(num.begin( ), num.end( )) - '0';
        int cnt = inf;
        if (curr - mx >= 0) cnt = min(cnt, 1 + go(go, curr - mx));
        return cnt;
    };

    cout << go(go, n) << endl;
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
