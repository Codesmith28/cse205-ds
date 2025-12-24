#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE #include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (?°?°)?? ??? */

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
        if (isPrime[i])
            primes.push_back(i);
    }
}

bool checkSum(int n) {
    for (int i = 0; i < primes.size(); i++) {
        int a = primes[i];
        int asq = a * a;
        if (asq >= n) { 
            break;
        }

        for (int j = i + 1; j < primes.size(); j++) { 
            int b = primes[j];
            int bsq = b * b;
            if (asq + bsq >= n) 
                break;

            int rem = n - asq - bsq;
            int c = sqrt(rem);
            if (c * c == rem && isPrime[c] && c != a && c != b) { 
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    cout << (checkSum(n) ? "Yes\n" : "No\n");
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