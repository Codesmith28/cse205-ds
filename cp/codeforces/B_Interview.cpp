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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int res = INT_MIN;

    auto ors = [&](int l, int r) -> int {
        int sa = 0, sb = 0;
        for (int i = l; i <= r; i++) {
            sa |= a[i];
            sb |= b[i];
        }
        return sa + sb;
    };

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            res = max(res, ors(l, r));
        }
    }

    cout << res << endl;
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