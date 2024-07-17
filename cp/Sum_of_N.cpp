#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

const int N = 2e6;
vector<bool> isPrime(N, true);
vector<int> primes;
void sieve() {
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

int spf(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i] && n % i == 0) return i;
    }
    return n;
}

void solve() {
    int k;
    cin >> k;
    int x = spf(k);

    int ans = 0, i = 0;
    while (primes[i] != x) {
        ans += k * primes[i];
        i++;
    }
    ans += k * x;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    sieve();

    while (testCases--) {
        solve();
    }

    return 0;
}