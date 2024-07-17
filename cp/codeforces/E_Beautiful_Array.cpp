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

int k;
bool comp(int a, int b) {
    if ((a % k) == (b % k)) return a < b;
    return (a % k) < (b % k);
}

void solve() {
    int n;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(begin(a), end(a), comp);
    // dbg(a);

    
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