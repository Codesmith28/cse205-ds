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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int g = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] > a[k - 1]) g++;
    }

    if (g == 0) {
        swap(a[0], a[k - 1]);
        int mxid = max_element(a.begin( ), a.end( )) - a.begin( );
        int ans = 0;
        for (int i = 0; i < mxid; i++) {
            if (a[0] > a[i] && i != 0) ans++;
        }
        cout << ans << endl;
    } else {
        swap(a[0], a[k - 1]);
        int mxid = max_element(a.begin( ), a.end( )) - a.begin( );
        int ans1 = 0;
        for (int i = 0; i < mxid; i++) {
            if (a[0] > a[i] && i != 0) ans1++;
        }
        swap(a[0], a[k - 1]);

        swap(a[mxid], a[k - 1]);
        int ans2 = 0;
        if (mxid > 0) {
            int mxmx = *max_element(a.begin( ), a.begin( ) + mxid);
            a[mxid - 1] = mxmx;
        }
        for (int i = mxid - 1; i < k; i++) {
            if (a[mxid] > a[i] && i != mxid) ans2++;
        }
        swap(a[mxid], a[k - 1]);

        cout << max(ans1, ans2) << endl;
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
