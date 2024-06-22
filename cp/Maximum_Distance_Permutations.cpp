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

    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;

    if (n % 2) {
        for (int i = (n + 1) / 2; i <= n; i++) {
            cout << i << " ";
        }
        for (int i = 1; i < (n + 1) / 2; i++) {
            cout << i << " ";
        }
    } else {
        for (int i = n / 2 + 1; i <= n; i++) {
            cout << i << " ";
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << i << " ";
        }
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