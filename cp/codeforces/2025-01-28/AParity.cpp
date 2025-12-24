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
    int b, k;
    cin >> b >> k;
    vector<int> a(k);
    for (int &i : a) cin >> i;

    int odd_terms = 0;

    for (int i = 0; i < k; i++) {
        if ((a[i] % 2 == 1) && (b % 2 == 1)) {
            odd_terms++;
        }
    }

    if (a.back( ) % 2 == 1 && (b % 2 == 0)) odd_terms++;

    cout << (odd_terms % 2 == 0 ? "even" : "odd") << endl;
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
