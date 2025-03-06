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

const int N = 2e6;
vector<bool> isPrime(N, true);
vector<int> primes;

void solve( ) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
        if (l == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    } else {
        cout << r - l << endl;
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
