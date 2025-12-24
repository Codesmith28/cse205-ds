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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int mx = *max_element(begin(a), end(a));
    int mxc = max(a[0] + c, mx);
    int EZ = 0;
    if (mxc == a[0] + c) {
        EZ = 0;
    } else {
        EZ = find(begin(a), end(a), mx) - begin(a);
    }

    int undec = c;
    for (int i = 0; i < n; i++) {
        int ans;

        if (i == EZ)
            ans = 0;
        else if (undec + a[i] >= mx) {
            ans = i;
        } else {
            ans = i + 1;
        }

        undec += a[i];
        cout << ans << " ";
    }
    cout << endl;
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