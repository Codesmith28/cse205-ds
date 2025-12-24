#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define endl "\n"

void solve( ) {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    for (int i = 2; i <= n; i += 2) cout << i << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) solve( );

    return 0;
}
