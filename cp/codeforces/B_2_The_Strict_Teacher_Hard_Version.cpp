#include <algorithm>
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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> b(m), a(q);
    for (int &i : b) cin >> i;
    for (int &i : a) cin >> i;
    sort(begin(b), end(b));

    for (int i = 0; i < q; i++) {
        int d = a[i];
        int ans = 0;

        if (d < b[0]) {
            ans = b[0] - 1;
        } else if (d < b[m - 1]) {
            auto idx = upper_bound(begin(b), end(b), d) - begin(b) - 1;
            ans = (b[idx + 1] - b[idx]) / 2;
        } else {
            ans = n - b[m - 1];
        }

        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}