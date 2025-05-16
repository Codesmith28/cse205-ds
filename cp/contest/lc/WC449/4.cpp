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
    bool canPartitionGrid(vector<vector<int>> &grid) {
        using ll = long long;
        ll total = 0;
        for (auto &it : grid) total += accumulate(it.begin( ), it.end( ), 0);

        auto chk = [&](vector<vector<int>> &grid) -> bool {
            set<int> vis;
            int n = grid.size( );

            ll top = 0;
            for (int i = 0; i < n; i++) {
                for (int it : grid[i]) vis.insert(it);
                top += accumulate(grid[i].begin( ), grid[i].end( ), 0);
                ll bot = total - top;
                ll diff = top - bot;
                if (diff == 0 || diff == grid[0][0] || diff == grid[0].back( ) || diff == grid[i][0]) return true;
                if (grid[0].size( ) > 1 && i > 0 && vis.count(diff)) return true;
            }

            return false;
        };

        // transpose the grid:
        auto transpose = [&](vector<vector<int>> &grid) {
            vector<vector<int>> t(grid[0].size( ), vector<int>(grid.size( )));
            for (int i = 0; i < grid.size( ); i++)
                for (int j = 0; j < grid[0].size( ); j++) t[j][i] = grid[i][j];
            return t;
        };

        vector<vector<int>> g2 = transpose(grid);
        if (chk(g2)) return true;
        reverse(g2.begin( ), g2.end( ));
        if (chk(g2)) return true;

        if (chk(grid)) return true;
        reverse(grid.begin( ), grid.end( ));
        if (chk(grid)) return true;

        return false;
    }
};

int main( ) {
    vector<vector<vector<int>>> grid{
        {{1, 4},    {2, 3}   },
        {{1, 2},    {3, 4}   },
        {{1, 2, 4}, {2, 3, 5}},
        {{4, 1, 8}, {3, 2, 6}},
    };
    Solution sol;
    for (auto it : grid) cout << sol.canPartitionGrid(it) << endl;
    return 0;
}
