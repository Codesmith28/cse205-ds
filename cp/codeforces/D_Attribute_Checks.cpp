#include <algorithm>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    for (int &i : r) cin >> i;

    vector<int> dp(m + 1, -1e9);
    dp[0] = 0;

    auto make_diff = [&]() -> void {
        for (int i = m; i > 0; i--) dp[i] = dp[i] - dp[i - 1];
    };
    auto make_dp = [&]() -> void {
        for (int i = 1; i <= m; i++) dp[i] += dp[i - 1];
    };

    make_diff();
    int total_pts = 0;

    auto add_pts = [&]() -> void {
        make_dp();
        total_pts++;
        for (int i = m; i > 0; i--) dp[i] = max(dp[i], dp[i - 1]);
        make_diff();
    };

    for (int i = 0; i < n; i++) {
        if (r[i] == 0) {
            add_pts();
            continue;
        }

        if (r[i] > 0) {
            dp[r[i]]++;
            continue;
        }

        r[i] = total_pts - abs(r[i]);

        if (r[i] < 0) {
            continue;
        }

        dp[0]++;
        if (r[i] < m) dp[r[i] + 1]--;
    }

    make_dp();
    cout << *max_element(dp.begin(), dp.end()) << endl;
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