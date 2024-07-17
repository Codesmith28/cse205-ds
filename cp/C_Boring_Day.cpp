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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int curr = 0, ans = 0;
    int st = 0, en = 0;
    while (st < n) {
        while (curr < l and en < n) {
            curr += a[en];
            en++;
        }
        if (curr >= l and curr <= r) {
            ans++;
            st = en;
            curr = 0;
        } else {
            curr -= a[st];
            st++;
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