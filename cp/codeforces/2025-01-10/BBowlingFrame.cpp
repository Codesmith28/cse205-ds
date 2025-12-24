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
    int w, b;
    cin >> w >> b;

    int l = 0, r = w + b;
    int k = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid * (mid + 1) / 2 <= w + b) {
            k = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << k << endl;
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
