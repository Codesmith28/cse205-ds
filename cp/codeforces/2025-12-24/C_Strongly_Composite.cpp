#include <bits/stdc++.h>
#include <unordered_map>
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

const int N = 1e7;
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

// strongly composite numbers:
// number of distinct prime factors < total factors

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    unordered_map<int, int> fq;
    for (int num : a) {
        int temp = num;
        for (int p : primes) {
            if (p * p > temp) break;
            while (temp % p == 0) {
                fq[p]++;
                temp /= p;
            }
        }
        if (temp != 1) fq[temp]++;
    }

    // [p p] -> 1 grp
    // [p p p] -> 1 grp
    // [p p p p] -> 2 grps [p p] + [p p]
    // [p q] -> 0 grps
    // [p q r] -> 1 grp
    // [p q r r] -> 1 grp as we cannot do [p q] [r r]
    // [p q r r r] -> 2 grps: [r r] [p q r]

    int grps = 0;
    int rem = 0;

    for (auto [k, v] : fq) {
        grps += v / 2;
        rem += v % 2;
    }

    grps += rem / 3;
    cout << grps << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;
    sieve( );

    while (testCases--) {
        solve( );
    }

    return 0;
}