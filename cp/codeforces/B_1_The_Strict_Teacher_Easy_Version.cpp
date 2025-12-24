#include <bits/stdc++.h>
#include <vector>
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
    int n, m, q;
    cin >> n >> m >> q;

    int b1, b2;
    cin >> b1 >> b2;
    if (b1 > b2) swap(b1, b2);
    int a;
    cin >> a;

    if (a < b1) {
        cout << b1 - 1 << endl;
    } else if (a > b1 and a < b2) {
        cout << (b2 - b1) / 2 << endl;
    } else {
        cout << n - b2 << endl;
    }
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