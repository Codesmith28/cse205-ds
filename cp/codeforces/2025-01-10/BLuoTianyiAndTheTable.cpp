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
    int n, m;
    cin >> n >> m;
    vector<int> b(n * m);
    for (int &i : b) cin >> i;

    sort(b.begin( ), b.end( ), greater<int>( ));
    int sz = n * m - 1;

    if (n > m) swap(n, m);
    int ans1 = 0, ans2 = 0;

    // n < m
    ans1 += b[0] * sz;
    ans1 -= (n - 1) * b[sz - 1];
    ans1 -= (sz - (n - 1)) * b[sz];

    ans2 -= b[sz] * sz;
    ans2 += (n - 1) * b[1];
    ans2 += (sz - (n - 1)) * b[0];

    cout << max(ans1, ans2) << endl;
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
