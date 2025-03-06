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
    int o = 0, e1 = 0, e2 = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.length( ) % 2 == 1) {
            o++;
        } else {
            int zcnt = count(s.begin( ), s.end( ), '0');
            if (zcnt % 2 == 0) {
                e1++;
            } else {
                e2++;
            }
        }
    }

    int result = n - ((o == 0 && e2 % 2 == 1) ? 1 : 0);
    cout << result << endl;
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
