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
    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    for (int &i : wt) cin >> i;

    int res = 0;
    sort(wt.begin( ), wt.end( ));
    for (int i = 0, j = n - 1; i <= j;) {
        if (wt[i] + wt[j] <= x)
            i++, j--;
        else
            j--;
        res++;
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