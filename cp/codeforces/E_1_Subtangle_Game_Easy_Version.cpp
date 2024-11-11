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
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l);
    vector<vector<int>> b(n, vector<int>(m));

    for (int &i : a) cin >> i;
    for (auto &i : b)
        for (int &j : i) cin >> j;

    auto dfs = [&](int idx, int r, int c, auto &&dfs) -> bool {
        if (idx == a.size()) return false;

        for (int i = r; i < n; i++) {
            for (int j = c; j < m; j++) {
                if (b[i][j] == a[idx]) {
                    if (idx == a.size() - 1 or !dfs(idx + 1, i + 1, j + 1, dfs)) {
                        return true;
                    }
                }
            }
        }

        return false;
    };

    cout << (dfs(0, 0, 0, dfs) ? "T" : "N") << endl;
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