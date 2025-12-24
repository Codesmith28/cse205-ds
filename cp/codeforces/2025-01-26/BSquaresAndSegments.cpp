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

    int s = floor(sqrt(n));
    int a1 = s * s;
    int a2 = (s + 1) * (s + 1);
    int a3 = s * (s + 1);

    if (n == a1) {
        cout << 2 * s << endl;
    } else if (n > a1 && n < a3) {
        cout << 2 * s + 1 << endl;
    } else if (n == a3) {
        cout << 2 * s + 1 << endl;
    } else if (n > a3 && n < a2) {
        cout << 2 * s + 2 << endl;
    } else if (n == a2) {
        cout << 2 * s + 2 << endl;
    }
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
