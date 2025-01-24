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

    if (k == 1) {
        cout << 1 << endl;
    } else if (k == 2) {
        if (m <= n) {
            cout << m << endl;
        } else {
            int mul = (m - n) / n;
            cout << mul + n << endl;
        }
    } else if (k == 3) {
        if (m <= n) {
            cout << 0 << endl;
        } else {
            int mul = (m - n) / (n);
            cout << m - mul - n << endl;
        }
    } else {
        cout << 0 << endl;
    }
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
