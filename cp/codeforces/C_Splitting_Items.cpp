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

    sort(begin(a), end(a), greater<int>());

    int A = 0, B = 0;
    A += a[0];
    
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            int diff = min(a[i - 1], a[i] + k);
            B += diff;
            k -= diff - a[i];
        } else {
            A += a[i];
        }
    }

    cout << A - B << endl;
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