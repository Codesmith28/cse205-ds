#include <bits/stdc++.h>
#include <vector>
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
    vector<pii> ab(n);
    for (auto &it : ab) cin >> it.first;
    for (auto &it : ab) cin >> it.second;

    sort(begin(ab), end(ab));
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