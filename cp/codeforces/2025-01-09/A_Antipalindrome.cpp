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

bool is_palin(string &s) {
    int n = s.size( );
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void solve( ) {
    string s;
    cin >> s;
    int n = s.size( );
    int ans = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            string sub = s.substr(i, len);
            if (!is_palin(sub)) {
                ans = max(ans, len);
            }
        }
    }

    cout << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}