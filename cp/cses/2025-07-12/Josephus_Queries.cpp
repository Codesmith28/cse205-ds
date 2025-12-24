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
    int a, b;
    cin >> a >> b;

    auto dfs = [&](auto &&go, int n, int k) -> int {
        if (n == 1) return 1;
        if (k <= (n + 1) / 2) {
            if (2 * k > n)
                return (2 * k) % n;
            else
                return 2 * k;
        }
        int rem = go(go, n / 2, k - (n + 1) / 2);
        if (n % 2 == 1)
            return 2 * rem + 1;
        else
            return 2 * rem - 1;
    };

    cout << dfs(dfs, a, b) << endl;
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