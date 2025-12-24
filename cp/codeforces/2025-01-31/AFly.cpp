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

const double EPS = 1e-7;
const int inf = 1e18;
int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int &i : a) {
        cin >> i;
        if (i <= 1) {
            cout << -1 << endl;
            return;
        }
        i--;
    }
    for (int &i : b) {
        cin >> i;
        if (i <= 1) {
            cout << -1 << endl;
            return;
        }
        i--;
    }

    double fuel = m;
    fuel += fuel / a[0];
    for (int i = 1; i < n; i++) {
        fuel += fuel / b[i];
        fuel += fuel / a[i];
    }
    fuel += fuel / b[0];

    cout << fixed << setprecision(10) << fuel - m << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
