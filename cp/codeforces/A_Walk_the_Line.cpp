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

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (n == 1) {
        cout << "Case #" << tc + 1 << ": " << (a[0] <= k ? "YES" : "NO") << endl;
        return;
    }

    sort(a.begin(), a.end());
    int total = a[0] * (2 * (n - 1) - 1);

    cout << "Case #" << tc + 1 << ": " << (total <= k ? "YES" : "NO") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        solve(i);
    }

    return 0;
}