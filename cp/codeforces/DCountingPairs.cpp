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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin( ), a.end( ));
    int total = accumulate(a.begin( ), a.end( ), 0);

    auto count_pairs = [&](int sum) -> int {
        /*count pairs such that total - (a[i] + a[j] ) < sum */
    };

    cout << count_pairs(y + 1) - count_pairs(x) << endl;
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
