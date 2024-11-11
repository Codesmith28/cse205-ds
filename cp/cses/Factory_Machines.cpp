#include <bits/stdc++.h>
#include <cmath>
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
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    int mx = 0;
    for (int &i : a) {
        cin >> i;
        mx = max(mx, i);
    }

    auto check = [&](int x) -> bool {
        int res = 0;
        for (int i : a) {
            res += x / i;
            if (res >= t) {
                return true;
            }
        }
        return res >= t;
    };

    int low = 1, high = mx * t, res = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
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
