#include <bits/stdc++.h>
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
const int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pii> q;

    // Check borders
    auto is_border = [&](int i, int j) -> bool {
        return (i == 0 && a[i][j] == 'U') || (i == n - 1 && a[i][j] == 'D') || (j == 0 && a[i][j] == 'L') || (j == m - 1 && a[i][j] == 'R');
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_border(i, j)) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    vector<int> dir = {0, 1, 0, -1, 0};
    map<char, pii> mp = {
        {'U', {-1, 0}},
        {'D', {1, 0} },
        {'L', {0, -1}},
        {'R', {0, 1} }
    };

    auto points = [&](int i, int j, int di, int dj) -> bool {
        return (i >= 0 && i < n && j >= 0 && j < m) && (mp[a[i][j]] == make_pair(-di, -dj));
    };

    auto adj = [&](int i, int j) -> void {
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (vis[i][j] || a[i][j] != '?') return;

        bool sep = true;
        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
                sep = false;
                break;
            }
        }

        if (sep) {
            vis[i][j] = true;
            q.push({i, j});
        }
    };

    while (!q.empty( )) {
        auto [i, j] = q.front( );
        q.pop( );

        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];

            if (points(ni, nj, dir[d], dir[d + 1])) {
                if (!vis[ni][nj]) {
                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }

            adj(ni, nj);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) ans++;
        }
    }

    cout << ans << endl;
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
