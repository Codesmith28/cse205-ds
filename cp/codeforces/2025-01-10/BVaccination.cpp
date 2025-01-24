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
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> t(n);
    for (int &i : t) cin >> i;

    int l = 0, res = 0;

    while (l < n) {
        res++;
        int mx_t = t[l] + w + d;
        int r = l;

        while ((r < n) && (r - l + 1 <= k) && (t[r] <= mx_t)) r++;
        l = r;
    }

    cout << res << endl;
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
