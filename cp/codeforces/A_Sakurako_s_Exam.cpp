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
    int a, b;
    cin >> a >> b;

    b %= 2;

    if (b == 0) {
        if (a % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        if (a < 2)
            cout << "NO\n";
        else {
            if (a % 2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
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