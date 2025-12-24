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

const int N = 1e4;
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
    int n, m;
    cin >> n >> m;
    int x = 1;

    bool flag = isPrime[n] || isPrime[m];
    vector<vector<int>> g(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        if (!flag) {
            for (int j = 0; j < m; j++) g[i][j] = x++;
        } else {
            if (i % 2 == 0)
                for (int j = 0; j < m; j++) g[i][j] = x++;
            else // print in reverse:
                for (int j = m - 1; j >= 0; j--) g[i][j] = x++;
        }
    }

    for (auto it : g) {
        for (auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    sieve( );
    while (test_cases--) {
        solve( );
    }

    return 0;
}
