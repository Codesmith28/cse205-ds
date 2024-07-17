#include <algorithm>
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
    int n, m;
    cin >> n >> m;
    vector<int> t(n), c(m);
    for (int &i : t) cin >> i;
    for (int &i : c) cin >> i;

    multiset<int> ts(begin(t), end(t));

    for (int i : c) {
        auto it = ts.upper_bound(i);
        if (it == begin(ts)) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            ts.erase(it);
        }
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