#include <bits/stdc++.h>
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

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> row_sum(n, vector<int>(m, 0));
    vector<vector<int>> col_sum(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) row_sum[i][0] = grid[i][0];
    for (int j = 0; j < m; j++) col_sum[0][j] = grid[0][j];

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            row_sum[i][j] = row_sum[i][j - 1] + grid[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            col_sum[i][j] = col_sum[i - 1][j] + grid[i][j];
        }
    }

    bool valid = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int r = i + 1, c = j + 1;
            if (grid[i][j]) {
                // dbg(i, j, row_sum[i][j], col_sum[i][j]);
                bool poss = (row_sum[i][j] == c || col_sum[i][j] == r);
                if (!poss) valid = false;
            }
        }
    }

    cout << (valid ? "YES" : "NO") << endl;
    // dbg("---");
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
