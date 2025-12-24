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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > c or (a == c and b > d)) {
        swap(a, c);
        swap(b, d);
    }

    if (b < c) {
        cout << 1 << endl;
        return;
    }

    if (b == c) {
        if (d != c and a != b) {
            cout << 2 << endl;
            return;
        }
    }

    if (c == a and d > b) {
        cout << b - a + 1 << endl;
        return;
    }

    if (c < b and d > b) {
        cout << b - c + 2 << endl;
        return;
    }

    if (d == b and c > a) {
        cout << d - c + 1 << endl;
        return;
    }

    if (c > a and d < b) {
        cout << d - c + 2 << endl;
        return;
    }

    cout << d - c << endl;
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