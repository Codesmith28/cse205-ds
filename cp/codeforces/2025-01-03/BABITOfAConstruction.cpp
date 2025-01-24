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

    if (n == 1) {
        cout << k << endl;
    } else {
        int msb = 0;
        for (int i = 0; i < 31; i++) {
            if (k & (1 << i)) {
                msb = i;
            }
        }
        vector<int> ans(n);

        ans[0] = (1 << msb) - 1;
        ans[1] = k - ans[0];
        for (int i = 2; i < n; i++) ans[i] = 0;
        for (int &i : ans) cout << i << " ";
        cout << endl;
    }
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
