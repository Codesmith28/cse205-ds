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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int &i : c) cin >> i;

    int lcnt = k, rcnt = k;
    if (c[0] == c[n - 1]) {
        lcnt = k / 2;
        rcnt = k - lcnt;
    }

    int l = 0, r = 0;
    int i = 0, j = n - 1;

    for (; i < n && l < lcnt; i++) {
        if (c[i] == c[0]) l++;
    }
    for (; j >= 0 && r < rcnt; j--) {
        if (c[j] == c[n - 1]) r++;
    }

    cout << ((i - 1) < (j + 1) ? "YES" : "NO") << endl;
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
