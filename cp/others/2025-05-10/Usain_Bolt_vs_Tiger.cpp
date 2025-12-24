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
    int f, db, ta, bs;
    cin >> f >> db >> ta >> bs;

    double time = (f) / (1.0 * bs);
    double time2 = sqrt(2.0 * (f + db) / ta);

    if (time2 <= time) {
        cout << "Tiger" << endl;
    } else {
        cout << "Bolt" << endl;
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