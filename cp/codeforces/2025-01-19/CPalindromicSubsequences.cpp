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
    int n;
    cin >> n;

    if (n == 6) {
        cout << "1 1 2 3 1 2" << endl;
    } else if (n == 9) {
        cout << "7 3 3 7 5 3 7 7 3" << endl;
    } else if (n == 15) {
        cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8" << endl;
    } else {
        for (int i = 1; i <= n - 2; i++) cout << i << " ";
        cout << "1 2" << endl;
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
