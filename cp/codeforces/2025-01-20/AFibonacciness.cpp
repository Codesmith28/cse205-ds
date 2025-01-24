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
    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        if (i != 2) cin >> a[i];
    }

    auto fib = [&](int x) {
        a[2] = x;
        int cnt = 0;
        for (int i = 2; i < 5; i++) {
            if (a[i] == a[i - 1] + a[i - 2]) cnt++;
        }
        return cnt;
    };

    int res = 0;
    for (int i = -100; i <= 100; i++) {
        res = max(res, fib(i));
    }

    cout << res << endl;
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
