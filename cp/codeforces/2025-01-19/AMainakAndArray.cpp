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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int r2, r3, r4;
    r2 = r3 = r4 = 0;

    for (int i = 0; i < n; i++) r2 = max(r2, a[(i - 1 + n) % n] - a[i]);
    for (int i = 0; i < n - 1; i++) r3 = max(r3, a[n - 1] - a[i]);
    for (int i = 1; i < n; i++) r4 = max(r4, a[i] - a[0]);

    cout << max({r2, r3, r4}) << endl;
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
