#include <algorithm>
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> allow(n);
    vector<int> apart(m);
    for (int &i : allow) cin >> i;
    for (int &i : apart) cin >> i;

    sort(allow.begin( ), allow.end( ));
    sort(apart.begin( ), apart.end( ));

    int j = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        int mn = allow[i] - k;
        int mx = allow[i] + k;
        while (j < m && apart[j] < mn) j++;
        if (j < m && apart[j] <= mx) res++, j++;
    }

    cout << res << endl;
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