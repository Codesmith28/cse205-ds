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

bool comp(pii a, pii b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, v[i] * a[j] + v[j] * a[i]);
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