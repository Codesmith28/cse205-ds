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
    int n;
    cin >> n;
    if (n & 1) {
        // for x, y, z:
        // y - x -> prime, z - y -> prime, z - x -> prime
        // (z - x) = (z - y) + (y - x) | sum of 2 primes = prime => 9, 16, 25 {pythagorean triplet}
        // For odd n, no solution if n <= 25
        if (n < 27) {
            cout << -1 << endl;
            return;
        }

        vector<int> base = {1, 3, 3, 4, 4, 5, 5, 6, 6, 1, 2, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 1, 2};

        // If n > 27, append extra pairs with distance 1
        if (n > 27) {
            int fill = 14;
            int extra_pairs = (n - 27) / 2;
            for (int i = 0; i < extra_pairs; i++) {
                base.push_back(fill);
                base.push_back(fill);
                fill++;
            }
        }

        for (int x : base) cout << x << " ";
        cout << endl;

    } else {
        // Even n: simple 1 1 2 2 3 3 ...
        int fill = 1;
        for (int i = 0; i < n; i++) {
            cout << fill << " ";
            if (i % 2 == 1) fill++;
        }
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
