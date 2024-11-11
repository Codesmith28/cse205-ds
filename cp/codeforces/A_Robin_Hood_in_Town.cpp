#include <bits/stdc++.h>
#include <numeric>
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    int sum = accumulate(a.begin(), a.end(), 0LL);
    if (n < 3) {
        cout << -1 << endl;
    } else {
        int val = a[n / 2];
        int res = 2 * val * n - sum;
        cout << max(0LL, res + 1) << endl;
    }
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