#include <bits/stdc++.h>
#include <climits>
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
    int n;
    cin >> n;

    map<int, int> fq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fq[x]++;
    }

    int mn = INT_MAX;
    for (auto it : fq) {
        mn = min(mn, (n - it.second) * it.first);
    }

    // if all 1
    cout << min(mn, n) << endl;
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