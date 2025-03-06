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
    int a1, a2, k1, k2;
    cin >> a1 >> a2 >> k1 >> k2;
    int n;
    cin >> n;

    int threshold = (k1 - 1) * a1 + (k2 - 1) * a2;
    int mn = max(0LL, n - threshold);

    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }

    int mx = 0;
    int card_cnt1 = a1 * k1;

    if (card_cnt1 >= n) {
        mx = n / k1;
    } else {
        mx = a1 + (n - card_cnt1) / k2;
    }

    cout << mn << " " << mx << endl;
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
