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
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = (n * (n + 1)) / 2;
    int cnt = 0; // number of free items:

    for (int i = n - 1; i >= 0; i--) {
        if (cnt >= i) break;

        if (s[i] == '1') { // make free
            cnt++;
            ans -= (i + 1);
        } else { // purchase
            cnt--;
            if (cnt < 0) cnt = 0;
        }
    }

    cout << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
