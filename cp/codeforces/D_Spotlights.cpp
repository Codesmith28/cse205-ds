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
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &i : a)
        for (auto &j : i) cin >> j;

    int res = 0;

    vector<vector<int>> up(n, vector<int>(m, -1));
    vector<vector<int>> down(n, vector<int>(m, -1));
    vector<vector<int>> left(n, vector<int>(m, -1));
    vector<vector<int>> right(n, vector<int>(m, -1));

    for (int j = 0; j < m; j++) {
        int u = -1, d = -1;
        for (int i = 0, k = n - 1; i < n; i++, k--) {
            if (a[i][j] == 1) u = i;
            if (a[k][j] == 1) d = k;
            up[i][j] = u;
            down[k][j] = d;
        }
    }

    for (int i = 0; i < n; i++) {
        int l = -1, r = -1;
        for (int j = 0, k = m - 1; j < m; j++, k--) {
            if (a[i][j] == 1) l = j;
            if (a[i][k] == 1) r = k;
            left[i][j] = l;
            right[i][k] = r;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                res += ((up[i][j] != -1) + (down[i][j] != -1) + (left[i][j] != -1) + (right[i][j] != -1));
            }
        }
    }

    cout << res << endl;
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