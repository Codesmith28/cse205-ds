#include <bits/stdc++.h>
#include <string>
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

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }

    int ans = 0, curr = 0, place = 0;
    for (int i = n - 1; i >= 0; i--) {
        int k = ((i * (i + 1) / 2) % mod);
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