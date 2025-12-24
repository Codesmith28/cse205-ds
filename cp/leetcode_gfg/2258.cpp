#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution {
  public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dir = {0, 1, 0, -1, 0};

        vector<vector<int>> timed(n, vector<int>(m, 1e9));
        queue<pii> q;
        map<pii, bool> vis;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[{i, j}] = true;
                    timed[i][j] = 0;
                } else if (grid[i][j] == 2) {
                    timed[i][j] = -1;
                }
            }
        }

        int time = 0;
        while (!q.empty()) {
            time++;
            int sz = q.size();
            while (sz--) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = cx + dir[d], y = cy + dir[d + 1];
                    if (x >= 0 and x < n and y >= 0 and y < m and timed[x][y] != -1 and !vis[{x, y}]) {
                        timed[x][y] = time;
                        vis[{x, y}] = true;
                        q.push({x, y});
                    }
                }
            }
        }

        auto reachable = [&](int x, int y) -> bool { return x >= 0 and x < n and y >= 0 and y < m and timed[x][y] != -1 && !vis[{x, y}]; };

        auto isPossible = [&](int time) -> bool {
            vis.clear();
            queue<pii> path;
            int curr = time;

            if (timed[0][0] <= curr) return false;

            path.push({0, 0});
            vis[{0, 0}] = true;

            while (!path.empty()) {
                curr++;
                int sz = path.size();

                while (sz--) {
                    auto [cx, cy] = path.front();
                    path.pop();

                    for (int d = 0; d < 4; d++) {
                        int x = cx + dir[d], y = cy + dir[d + 1];

                        if (reachable(x, y)) {
                            if (x == n - 1 and y == m - 1 and curr <= timed[x][y]) return true;
                            if (curr < timed[x][y]) {
                                vis[{x, y}] = true;
                                path.push({x, y});
                            }
                        }
                    }
                }
            }

            return false;
        };

        int low = 0, high = n * m;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid)) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }

        return ans == n * m ? 1e9 : ans;
    }
};

int main() {
    Solution sol;
    vector<vector<vector<int>>> grids = {
        {{0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 2, 1, 0}, {0, 2, 0, 0, 1, 2, 0}, {0, 0, 2, 2, 2, 0, 2}, {0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0}, {0, 1, 2, 0}, {0, 2, 0, 0}},
        {{0, 0, 0}, {2, 2, 0}, {1, 2, 0}},
        {{0, 2, 0, 0, 1}, {0, 2, 0, 2, 2}, {0, 2, 0, 0, 0}, {0, 0, 2, 2, 0}, {0, 0, 0, 0, 0}}
    };
    for (auto &it : grids) {
        cout << sol.maximumMinutes(it) << endl;
    }
    return 0;
}