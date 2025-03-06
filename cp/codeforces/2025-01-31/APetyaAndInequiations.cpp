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
    int n, x, y;
    cin >> n >> x >> y;

    int a = y - (n - 1);
    if (a <= 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> z(n);
    for (int i = 0; i < n - 1; i++) z[i] = 1;
    z[n - 1] = a;

    int ss = 0;
    for (int &i : z) ss += i * i;
    if (ss >= x) {
        for (int &i : z) cout << i << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
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
