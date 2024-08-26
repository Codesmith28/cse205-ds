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

    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);
    int mid = n / 2;

    a[mid] = n;

    int o = 1;
    for (int i = mid + 1; i < n; i++) {
        a[i] = o;
        o += 2;
    }

    int e = 2;
    for (int i = mid - 1; i >= 0; i--) {
        a[i] = e;
        e += 2;
    }

    for (auto it : a) {
        cout << it << " ";
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