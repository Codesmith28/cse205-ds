#include <algorithm>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pii a, b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') a = {i, j};
            if (grid[i][j] == 'B') b = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[a.first][a.second] = true;

    vector<int> dir = {0, 1, 0, -1, 0};
    vector<char> dirChar = {'R', 'D', 'L', 'U'};

    vector<vector<pii>> par(n, vector<pii>(m));
    queue<pii> nodes;
    nodes.push(a);

    auto chk = [&](int x, int y) -> bool {
        return x >= 0 and y >= 0 and x < n and y < m and !vis[x][y] and grid[x][y] != '#';
    };

    bool reached = false;
    while (!nodes.empty() and !reached) {
        auto [i, j] = nodes.front();
        nodes.pop();

        for (int d = 0; d < 4; d++) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (chk(x, y)) {
                vis[x][y] = true;
                par[x][y] = {i, j};
                nodes.push({x, y});
                if (grid[x][y] == 'B') {
                    reached = true;
                    break;
                }
            }
        }
    }

    if (reached) {
        vector<char> path;
        pii curr = b;

        while (curr != a) {
            pii prev = par[curr.first][curr.second];
            for (int d = 0; d < 4; d++) {
                int x = prev.first + dir[d], y = prev.second + dir[d + 1];
                if (x == curr.first and y == curr.second) {
                    path.push_back(dirChar[d]);
                    break;
                }
            }
            curr = prev;
        }

        cout << "YES" << endl;
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (char c : path) cout << c;
        cout << endl;

    } else {
        cout << "NO" << endl;
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
