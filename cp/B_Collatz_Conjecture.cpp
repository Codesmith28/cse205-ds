#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0 and x != 1) {

        // number of additions before x becomes divisible by y
        int add = (x / y + 1) * y - x;
        add = max(1ll, add);
        add = min(k, add);
        x += add;

        while (x % y == 0) {
            x /= y;
        }

        k -= add;
    }
    // now that x = 1, we can continue in a cycle
    cout << x + k % (y - 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}