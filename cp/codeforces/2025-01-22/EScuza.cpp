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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> pref(n), mxa(n);
    for (int i = 0; i < n; i++) {
        pref[i] = (i == 0 ? a[i] : pref[i - 1] + a[i]);
        mxa[i] = (i == 0 ? a[i] : max(mxa[i - 1], a[i]));
    }

    while (q--) {
        int k;
        cin >> k;
        int idx = upper_bound(mxa.begin( ), mxa.end( ), k) - mxa.begin( ) - 1;
        cout << (idx >= 0 ? pref[idx] : 0) << " ";
    }
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
