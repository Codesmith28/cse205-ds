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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    int ans = n + m; // max possible length
    for (int i = 0; i < m; i++) {
        int j = i;
        for (auto c : a) {
            if (j < m && b[j] == c) j++;
            ans = min(ans, n + m - (j - i));
        }
    }

    cout << ans << endl;
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