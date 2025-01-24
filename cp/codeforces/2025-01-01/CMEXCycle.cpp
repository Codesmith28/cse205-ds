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
    x--, y--;

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[(x + i) % n] = i % 2;
    if (n % 2 == 1 || (x - y) % 2 == 0) a[x] = 2;

    for (int i : a) cout << i << " ";
    cout << endl;
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
