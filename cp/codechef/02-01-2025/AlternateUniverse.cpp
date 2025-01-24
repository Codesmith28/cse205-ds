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
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    auto poss = [&](int v) -> bool {
        for (int i = 0; i < n; i++) {
            v = max(v, min(v, a[i]) + b[i]) - 1;
            if (v < 0) return false;
        }
        return true;
    };

    int l = 0, r = n, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (poss(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
