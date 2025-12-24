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

int mod = 1e9 + 7;

int fermet(int a, int m) {
    int res = 1;
    int exponent = m - 2;
    while (exponent) {
        if (exponent % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        exponent /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int sum = 0;
    for (int i : a) sum = (sum + i) % mod;

    int sop = 0;
    for (int i : a) {
        sum = (sum - i + mod) % mod;
        sop = (sop + i * sum % mod) % mod;
    }

    int pairs = (n * (n - 1) / 2) % mod;
    int exP = sop;

    cout << (exP * fermet(pairs, mod)) % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}