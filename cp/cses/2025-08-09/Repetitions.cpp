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
    int mx = 1;
    int cnt = 1;
    char prev = s[0];
    for (int i = 1; i < s.size( ); i++) {
        if (s[i] == prev) {
            cnt++;
        } else {
            prev = s[i];
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
    mx = max(mx, cnt);
    cout << mx << endl;
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
