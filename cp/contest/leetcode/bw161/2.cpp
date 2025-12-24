#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
      public:
        int countIslands(vector<vector<int>> &grid, int k) {
                using ll = long long;
                int n = grid.size( ), m = grid[0].size( );
                vector<int> dir = {1, 0, -1, 0, 1};

                vector<vector<int>> vis(n, vector<int>(m, false));
                auto valid = [&](int x, int y) -> bool {
                        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 0 && vis[x][y] == false;
                };

                auto dfs = [&](auto &&go, int x, int y) -> ll {
                        ll sum = grid[x][y];
                        vis[x][y] = true;
                        for (int d = 0; d < 4; d++) {
                                int nx = x + dir[d], ny = y + dir[d + 1];
                                if (valid(nx, ny)) {
                                        sum += go(go, nx, ny);
                                }
                        }
                        return sum;
                };

                vector<ll> values;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (valid(i, j)) {
                                        values.push_back(dfs(dfs, i, j));
                                }
                        }
                }

                int cnt = 0;
                for (auto i : values)
                        if (i % k == 0) cnt++;
                return cnt;
        }
};

int main( ) {
        // [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]]
        // 5
        // [[3,0,3,0],[0,3,0,3],[3,0,3,0]]
        // 3
        vector<vector<vector<int>>> grids = {
            {{0, 2, 1, 0, 0}, {0, 5, 0, 0, 5}, {0, 0, 1, 0, 0}, {0, 1, 4, 7, 0}, {0, 2, 0, 0, 8}},
            {{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}}
        };
        vector<int> k = {5, 3};
        Solution sol;
        for (int i = 0; i < grids.size( ); ++i) {
                int ans = sol.countIslands(grids[i], k[i]);
                cout << ans << endl;
        }
        return 0;
}