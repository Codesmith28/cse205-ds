#include <bits/stdc++.h>
#include <unordered_map>
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m, 0));
    unordered_map<int, pii> row, col;

    int t, e, c;
    int time = 0;
    while (q--) {
        cin >> t >> e >> c;
        e--;
        if (t == 1) {
            row[e] = {time, c};
        } else {
            col[e] = {time, c};
        }
        time++;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int val = 0;
            if (row.find(r) != row.end()) {
                val = row[r].second;
                if (col.find(c) != col.end()) {
                    if (row[r].first > col[c].first) {
                        val = row[r].second;
                    } else {
                        val = col[c].second;
                    }
                }
            } else if (col.find(c) != col.end()) {
                val = col[c].second;
            }
            a[r][c] = val;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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