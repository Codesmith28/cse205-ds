#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int  long long
#define endl "\n"

int mx = 1e6 + 1;
vector<int> divs(mx);

void precompute_divisors( ) {
    for (int i = 1; i < mx; i++) {
        for (int j = i; j < mx; j += i) {
            divs[j]++;
        }
    }
}

void solve( ) {
    int x;
    cin >> x;
    cout << divs[x] << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    precompute_divisors( );

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
