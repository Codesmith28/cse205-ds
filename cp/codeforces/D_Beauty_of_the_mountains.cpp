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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<string> bin(n);
    for (int i = 0; i < n; i++) cin >> bin[i];

    int diff = 0;
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    // storing the pref of number of 1s till i,j and also calculating diff
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (bin[i][j] == '1');
            if (bin[i][j] == '1') {
                diff += a[i][j];
            } else {
                diff -= a[i][j];
            }
        }
    }

    if (diff == 0) {
        cout << "YES\n";
        return;
    }

    // diophantine equation:
    int gcd = 0;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            int ones = pref[i + k][j + k] - pref[i][j + k] - pref[i + k][j] + pref[i][j];
            int imbalance = abs(k * k - 2 * ones);
            gcd = __gcd(gcd, imbalance);
        }
    }

    if (gcd == 0 or diff % gcd != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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