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

    int amx, bmx, neg, pos;
    amx = bmx = neg = pos = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i])
            amx += a[i];
        else if (a[i] < b[i])
            bmx += b[i];
        else {
            neg += (a[i] < 0);
            pos += (a[i] > 0);
        }
    }

    int ans = -1e9;
    for (int i = -neg; i <= pos; i++) {
        ans = max(ans, min(amx + i, bmx + pos - neg - i));
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
