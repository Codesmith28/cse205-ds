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

void solve() {
    int n, m;
    cin >> n >> m;
    int q = m / n;
    int r = m % n;

    if (r != 0) {
        cout << -1 << endl;
    } else {
        int cnt = 0;
        while (q % 2 == 0) {
            q /= 2;
            cnt++;
        }
        while (q % 3 == 0) {
            q /= 3;
            cnt++;
        }
        if (q == 1) {
            cout << cnt << endl;
        } else {
            cout << -1 << endl;
        }
    }
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