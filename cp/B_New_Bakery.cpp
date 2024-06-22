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
    int n, a, b;
    cin >> n >> a >> b;

    if (a > b) {
        cout << n * a << endl;
        return;
    }

    int x = b - a + 1;
    int k = min(n, x);

    cout << (n - k) * a + ((b + 1) * k) - (k) * (k + 1) / 2 << endl;
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