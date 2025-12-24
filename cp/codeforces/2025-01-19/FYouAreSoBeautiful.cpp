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

    map<int, int> lm, rm;
    for (int i = 0; i < n; i++) rm[a[i]] = i;
    for (int i = n - 1; i >= 0; i--) lm[a[i]] = i;

    vector<int> rmidx(n, 0);
    for (int i = 0; i < n; i++) {
        if (rm[a[i]] == i) rmidx[i] = 1;
    }

    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) suff[i] = suff[i + 1] + rmidx[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (lm[a[i]] == i) ans += suff[i];
    }

    cout << ans << endl;
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
