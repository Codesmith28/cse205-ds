#include <bits/stdc++.h>
#include <numeric>
#include <vector>
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

void solve() {
    int n;
    cin >> n;
    vector<pii> xh(n + 1);
    for (auto &it : xh) cin >> it.first >> it.second;

    int ans = 1; // first tree to left
    xh[n].first = INT_MAX;

    for (int i = 1; i < n; i++) {
        bool l = xh[i].first - xh[i].second > xh[i - 1].first;
        bool r = xh[i].first + xh[i].second < xh[i + 1].first;

        if (l) {
            ans++;
        } else if (r) {
            ans++;
            xh[i].first += xh[i].second;
        }
    }

    cout << ans << endl;
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