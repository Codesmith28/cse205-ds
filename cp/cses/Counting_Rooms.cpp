#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> dir = {0, 1, 0, -1, 0};

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    auto chk = [&](int x, int y) -> bool {
        return x >= 0 and y >= 0 and x < n and y < m and !vis[x][y] and grid[x][y] == '.';
    };

    auto dfs = [&](int i, int j, auto &&dfs) -> void {
        vis[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (chk(x, y)) {
                dfs(x, y, dfs);
            }
        }
    };

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] and grid[i][j] == '.') {
                dfs(i, j, dfs);
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}