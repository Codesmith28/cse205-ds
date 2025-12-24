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
    string a, b;
    cin >> a >> b;
    int n = a.size( );

    if (a == b) {
        cout << 2 * n << endl;
        return;
    }

    int i = 0;
    while (a[i] == b[i] && i < n) i++;

    if (a[i] + 2 <= b[i]) { // rem can be anything as it is within bounds
        cout << 2 * i << endl;
    } else {
        int x = i + 1;
        int res = 2 * i + 1;                          // for the first character that differs
        while (x < n && a[x] == '9' && b[x] == '0') { // any consec {1,9}
            res++;
            x++;
        }
        cout << res << endl;
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