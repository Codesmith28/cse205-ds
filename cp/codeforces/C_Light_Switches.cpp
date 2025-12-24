#include <bits/stdc++.h>
#include <climits>
#include <csetjmp>
#include <vector>
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

    sort(begin(a), end(a));
    int mx = a[n - 1];

    int tmin = mx - k, tmax = mx + k;
    int mn = INT_MAX;
    mx = 0;

    int ansNew = 0;
    for (int i = 0; i < n; i++) {
        int inc = max(0LL, (tmin - a[i]) / (2 * k));
        a[i] += inc * 2 * k;
        if (a[i] <= tmin) {
            a[i] += 2 * k;
        }

        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        ansNew = max(ansNew, a[i]);
    }

    if (mx >= tmax) {
        cout << -1 << endl;
    } else {
        if ((mx - mn) >= k)
            cout << -1 << endl;
        else
            cout << ansNew << endl;
    }
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}