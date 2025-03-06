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
    int n;
    cin >> n;

    auto f = [&](int n) -> int {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return i;
        }
        return n;
    };

    int x = f(n), cnt = 0;
    if (n % 2 == 1) {
        n -= x;
        cnt++;
    }

    cout << cnt + n / 2 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
