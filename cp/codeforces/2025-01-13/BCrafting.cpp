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
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    vector<int> diff(n);
    int neg = 0;
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
        if (diff[i] < 0) neg++;
    }

    if (neg > 1) {
        cout << "NO" << endl;
        return;
    }

    sort(diff.begin( ), diff.end( ));
    dbg(diff);

    if (abs(diff[0]) <= abs(diff[1])) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
