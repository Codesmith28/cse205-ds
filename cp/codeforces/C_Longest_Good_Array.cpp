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
    int l, r;
    cin >> l >> r;

    int diff = r - l;
    int st = 0, en = 2 * diff;

    while (st <= en) {
        int mid = (st + en) / 2;
        if (mid * (mid + 1) / 2 <= diff) {
            st = mid + 1;
        } else {
            en = mid - 1;
        }
    }

    cout << en + 1 << endl;
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