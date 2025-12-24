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
    int n, k;
    cin >> n >> k;
    int last = n - (k - 1);

    if (last % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) cout << 1 << " ";
        cout << last << endl;
        return;
    } else {
        last = n - 2 * (k - 1);
        if (last % 2 == 0 && last > 0) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) cout << 2 << " ";
            cout << last << endl;
            return;
        }
    }

    cout << "NO" << endl;
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