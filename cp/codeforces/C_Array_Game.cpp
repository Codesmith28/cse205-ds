#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    int mn = a[0];
    int diff = 1e18;
    for (int i = 1; i < n; i++) {
        diff = min(diff, abs(a[i] - a[i - 1]));
    }
    mn = min(mn, diff);

    if (k == 1) {
        cout << mn << endl;
    } else {
        diff = 1e18;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int currDiff = abs(a[i] - a[j]);
                int lb = lower_bound(a.begin(), a.end(), currDiff) - a.begin();
                diff = min(diff, abs(a[lb] - currDiff));
                if (lb > 0) {
                    diff = min(diff, abs(a[lb - 1] - currDiff));
                }
                if (lb < n - 1) {
                    diff = min(diff, abs(a[lb + 1] - currDiff));
                }
            }
        }
        mn = min(mn, diff);
        cout << mn << endl;
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