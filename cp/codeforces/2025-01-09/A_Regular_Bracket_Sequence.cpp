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
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    // if (( != )) => impossible
    if (c1 != c4) {
        cout << 0 << endl;
        return;
    }

    // if )( > 0 and (( = 0 => impossible
    if (c1 == 0 and c3 > 0) {
        cout << 0 << endl;
        return;
    }

    cout << 1 << endl;
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