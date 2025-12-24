#include <bits/stdc++.h>
#include <unordered_map>
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
    unordered_map<int, int> fq;
    int x;
    int mxfq = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        fq[x]++;
        mxfq = max(mxfq, fq[x]);
    }

    // get the one with max frequency
    cout << n - mxfq << endl;
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