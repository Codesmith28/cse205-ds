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
    string s;
    cin >> s;
    int o = 0, z = 0;
    for (char c : s) c == '1' ? o++ : z++;

    int n = s.size( ), i = 0;
    for (; i < n; i++) {
        if (s[i] == '1') {
            if (z > 0)
                z--;
            else
                break;
        }
        if (s[i] == '0') {
            if (o > 0)
                o--;
            else
                break;
        }
    }

    cout << n - i << endl;
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
