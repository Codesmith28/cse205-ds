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
    vector<int> a(14);
    for (int &i : a) cin >> i;

    auto distribute = [&](int idx) {
        int cnt = a[idx];
        a[idx] = 0;

        int q = cnt / 14;
        int r = cnt % 14;

        int i = idx;
        for (int i = 1; i <= 14; i++) a[(idx + i) % 14] += q;
        for (int i = 1; i <= r; i++) a[(idx + i) % 14]++;
    };

    auto sum = [&]( ) -> int {
        int s = 0;
        for (int &i : a)
            if (i % 2 == 0) s += i;
        return s;
    };

    int mx = 0;
    for (int i = 0; i < 14; i++) {
        vector<int> b = a;
        distribute(i);
        mx = max(mx, sum( ));
        a = b;
    }

    cout << mx << endl;
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
