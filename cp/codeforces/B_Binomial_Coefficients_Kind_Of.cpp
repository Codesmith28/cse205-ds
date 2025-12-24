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

int mod = 1e9 + 7;

int powFn(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int N;
    cin >> N;
    vector<int> t(N), k(N);
    for (int &i : t) cin >> i;
    for (int &i : k) cin >> i;

    for (int i = 0; i < N; i++) {
        cout << powFn(2, k[i]) % mod << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
