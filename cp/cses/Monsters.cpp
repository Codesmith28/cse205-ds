#include <bits/stdc++.h>
using namespace std;

/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    queue<pii> mon, me;

    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> mon_visited(n, vector<bool>(m, false));
    vector<vector<bool>> me_visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'M') {
                mon.push({i, j});
                mon_visited[i][j] = true;
            }
            if (g[i][j] == 'A') {
                me.push({i, j});
                me_visited[i][j] = true;
            }
        }
    }

    auto boundary_check = [&](int x, int y) -> bool {
        return x == 0 || y == 0 || x == n - 1 || y == m - 1;
    };

    vector<int> dir = {0, -1, 0, 1, 0};
    vector<char> dirc = {'L', 'U', 'R', 'D'};
    bool reached = false;

    vector<vector<pii>> mepar(n, vector<pii>(m));
    pii final;
    pii initial = me.front();

    auto meposs = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < n && y < m && g[x][y] != '#' && !me_visited[x][y] && !mon_visited[x][y];
    };
    auto monposs = [&](int x, int y) -> bool {
        return x >= 0 && y >= 0 && x < n && y < m && g[x][y] != '#' && !mon_visited[x][y];
    };

    // BFS loop
    while (!mon.empty() || !me.empty()) {
        // Move monsters first
        int mon_size = mon.size();
        while (mon_size--) {
            auto [moi, moj] = mon.front();
            mon.pop();

            for (int d = 0; d < 4; d++) {
                int x = moi + dir[d], y = moj + dir[d + 1];
                if (monposs(x, y)) {
                    mon.push({x, y});
                    mon_visited[x][y] = true;
                }
            }
        }

        // Move player
        int me_size = me.size();
        while (me_size--) {
            auto [mei, mej] = me.front();
            me.pop();

            for (int d = 0; d < 4; d++) {
                int x = mei + dir[d], y = mej + dir[d + 1];
                if (meposs(x, y)) {
                    me.push({x, y});
                    me_visited[x][y] = true;
                    mepar[x][y] = {mei, mej};
                    // Check if the player can escape
                    if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                        reached = true;
                        final = {x, y};
                        break;
                    }
                }
            }
            if (reached) break;
        }

        if (reached) break;
    }

    if (reached) {
        // Reconstruct path
        pii curr = final;
        vector<char> path;
        while (curr != initial) {
            pii prev = mepar[curr.first][curr.second];
            for (int d = 0; d < 4; d++) {
                int x = prev.first + dir[d], y = prev.second + dir[d + 1];
                if (x == curr.first && y == curr.second) {
                    path.push_back(dirc[d]);
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
