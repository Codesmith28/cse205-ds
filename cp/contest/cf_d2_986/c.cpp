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
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    /*vector<int> pref(n);*/
    /*pref[0] = a[0];*/
    /*for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];*/
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