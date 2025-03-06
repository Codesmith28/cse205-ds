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

const int N = 3e4 + 5;
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
    int n;
    cin >> n;
    int res = 0;

    for (int i = 1; i <= n; i++) {
        int j = 0, cnt = 0, flag = 1;
        while (primes[j] <= i) {
            if (i % primes[j] == 0) cnt++;
            if (cnt > 2) {
                flag = 0;
                break;
            }
            j++;
        }
        res += flag && (cnt == 2);
    }

    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    sieve( );
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
