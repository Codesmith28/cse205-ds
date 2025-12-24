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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        int other = x - e;
        if (mp.find(other) != mp.end( )) {
            cout << i + 1 << " " << mp[other] + 1 << endl;
            return;
        }
        mp[e] = i;
    }
    cout << "IMPOSSIBLE" << endl;
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