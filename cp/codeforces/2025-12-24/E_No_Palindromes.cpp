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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    string s;
    cin >> s;
    int n = s.size( );

    auto palin = [&](int l, int r) -> bool {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    };

    // entire string non pallin
    if (!palin(0, n - 1)) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << s << endl;
        return;
    }

    // all chars same
    int diff = -1;
    for (int i = 1; i < n; i++) {
        if (s[0] != s[i]) {
            diff = i;
            break;
        }
    }
    if (diff == -1) {
        cout << "NO" << endl;
        return;
    }

    bool suffPalin = (diff < n - 1) ? palin(diff + 1, n - 1) : true;
    if (!suffPalin && !palin(0, n + 1)) {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s.substr(0, diff + 1) << " " << s.substr(diff + 1) << endl;
        return;
    }

    // invalid indices
    if (diff == 1 || diff == (n - 1) / 2) {
        cout << "NO" << endl;
        return;
    }

    // fallback
    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s.substr(0, diff + 2) << " " << s.substr(diff + 2) << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}