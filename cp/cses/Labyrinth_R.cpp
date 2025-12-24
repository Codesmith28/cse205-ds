#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define int long long
#define pii pair<int, int>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pii start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    vector<int> dir = {0, 1, 0, -1, 0};
    vector<char> dirChar = {'R', 'D', 'L', 'U'};

    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = true;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (i == end.first && j == end.second) break;

        for (int d = 0; d < 4; d++) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && grid[x][y] != '#') {
                vis[x][y] = true;
                parent[x][y] = {i, j};
                q.push({x, y});
            }
        }
    }

    if (!vis[end.first][end.second]) {
        cout << "NO\n";
        return;
    }

    // Path reconstruction
    string path;
    pii cur = end;
    while (cur != start) {
        pii par = parent[cur.first][cur.second];
        for (int d = 0; d < 4; d++) {
            int x = par.first + dir[d], y = par.second + dir[d + 1];
            if (x == cur.first && y == cur.second) {
                path.push_back(dirChar[d]);
                break;
            }
        }
        cur = par;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
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
