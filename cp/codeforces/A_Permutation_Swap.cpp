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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> b = a;

    sort(b.begin( ), b.end( ));
    map<int, int> mp;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mp[abs(a[i] - b[i])]++;
        mx = max(mx, abs(a[i] - b[i]));
    }

    // gcd of all keys
    int gcd = 0;
    for (auto it : mp) {
        gcd = __gcd(gcd, it.first);
    }

    cout << gcd << endl;
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