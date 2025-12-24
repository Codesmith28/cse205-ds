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
    int n, q;
    cin >> n >> q;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        int max_left = -1;
        // Process range [a, b] from left to right
        for (int i = a; i <= b; i++) {
            if (h[i] > max_left) {
                ans++;
                max_left = h[i];
            }
        }
        cout << ans << endl;
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
