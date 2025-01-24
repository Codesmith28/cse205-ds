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
int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }

    queue<pii> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // Movement mapping
    map<pii, char> mp = {
        {{0, 1},  'L'},
        {{0, -1}, 'R'},
        {{1, 0},  'U'},
        {{-1, 0}, 'D'}
    };

    auto safe = [&](int ni, int nj, int di, int dj) -> bool {
        return ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && maze[ni][nj] == mp[{di, dj}];
    };

    vector<int> dir = {0, 1, 0, -1, 0};

    // Initialize BFS with border cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && maze[i][j] == 'U') || (i == n - 1 && maze[i][j] == 'D') || (j == 0 && maze[i][j] == 'L') || (j == m - 1 && maze[i][j] == 'R')) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    // BFS traversal
    while (!q.empty( )) {
        auto [i, j] = q.front( );
        q.pop( );

        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];

            if (safe(ni, nj, dir[d], dir[d + 1])) {
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }

    // Count unvisited cells
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
