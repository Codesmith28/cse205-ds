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

const int N = 2e6 + 2;
vector<bool> isPrime(N, true);
vector<int> primes;

void sieve( ) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void solve( ) {
    int n, k;
    cin >> n >> k;

    auto nc2 = [&](int n) {
        return n * (n - 1) / 2;
    };

    int mxp = nc2(n);
    if (k > mxp) {
        cout << -1 << endl;
        return;
    }

    int l = 1, r = 1e6;
    int e = -1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nc2(m) <= k) {
            e = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    /*dbg(e);*/

    vector<int> c1;
    int lcm_c1 = 1;
    for (int i = 0; i < e; i++) {
        c1.push_back(primes[i]);
        lcm_c1 = lcm_c1 * primes[i] / __gcd(lcm_c1, primes[i]);
    }

    vector<int> c2;
    int sz = n - e;
    for (int i = 1; i <= sz; i++) {
        c2.push_back(lcm_c1 * i);
    }

    for (int i : c1) cout << i << " ";
    for (int i : c2) cout << i << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve( );

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
