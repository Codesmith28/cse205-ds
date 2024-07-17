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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (b[j] >= a[i] - k && b[j] <= a[i] + k) {
            ans++;
            i++;
            j++;
        } else if (b[j] < a[i] - k) {
            j++;
        } else {
            i++;
        }
    }

    cout << ans << endl;
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