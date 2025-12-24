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

    map<int, int> fq;
    for (int &i : a) fq[i]++;

    // if a[i] == sz => we cannot have set of size sz
    // for any set of size sz to be valid => there shhould be exactly sz members present

    int ans = 0, pref = 0;
    for (int sz = 0; sz <= n; sz++) {
        if (fq[sz] == 0 && pref == sz) ans++;
        pref += fq[sz];
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
