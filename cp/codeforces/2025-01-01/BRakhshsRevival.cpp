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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    int len = 0, ans = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            len++;
        } else {
            len = 0;
        }

        if (len == m) {
            ans++;
            for (int j = i; j < min(i + k, n); j++) {
                s[j] = '1';
            }
            len = 0;
        }
    }

    dbg(s);
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
