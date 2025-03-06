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
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0) {
        cout << 0 << " " << 0 << endl;
        return;
    } else if (n == 0) {
        cout << "Impossible" << endl;
        return;
    } else if (m == 0) {
        cout << n << " " << n << endl;
        return;
    }

    int mx = n + m - 1;
    int mn = n + m - min(n, m);

    cout << mn << " " << mx << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
