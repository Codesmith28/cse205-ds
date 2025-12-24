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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int op = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) continue;
        op++;
        while (i < n - 1 and a[i] == a[i + 1]) i++;
        bool conv = false;
        while (i < n and __gcd(a[i], k) == k) {
            conv = true;
            i++;
        }
        if (i < n and conv) op++;
    }

    cout << min(2LL, op) << endl;
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