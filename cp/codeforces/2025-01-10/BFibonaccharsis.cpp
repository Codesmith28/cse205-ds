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
    int n, k;
    cin >> n >> k;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int c = n;
        int b = i;
        bool poss = true;

        for (int j = 0; j < k - 2; j++) {
            int a = c - b;
            if (a > b || a < 0) {
                poss = false;
                break;
            }
            c = b;
            b = a;
        }

        if (poss) ans++;
    }
    cout << ans << endl;
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
