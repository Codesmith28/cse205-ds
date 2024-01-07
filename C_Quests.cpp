#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int res = 0, sum = 0, mx = 0;
    for (int i = 0; i < min(n, k); i++) {
        // sum upto i:
        sum += a[i];
        // max value in b upto i:
        mx = max(mx, b[i]);
        // setting res to be the max sum possible using sum and max value in b upto i:
        res = max(res, sum + mx * (k - i - 1));
    }

    cout << res << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}