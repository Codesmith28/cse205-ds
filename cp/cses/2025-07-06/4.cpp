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
    int minMoves(int sx, int sy, int tx, int ty) {
        using ll = long long;
        using pll = pair<ll, ll>;
        set<pll> vis;

        int hops = 0;
        queue<pll> q;
        q.push({sx, sy});
        vis.insert({sx, sy});

        while (!q.empty( )) {
            int sz = q.size( );
            while (sz--) {
                auto [x, y] = q.front( );
                q.pop( );

                if (x == tx && y == ty) return hops;
                ll m = max(x, y);
                if (x + m <= tx && !vis.count({x + m, y})) {
                    vis.insert({x + m, y});
                    q.push({x + m, y});
                }
                if (y + m <= ty && !vis.count({x, y + m})) {
                    vis.insert({x, y + m});
                    q.push({x, y + m});
                }
            }
            hops++;
        }

        return -1;
    }
};

int main( ) {
    vector<int> sx = {
        1,
        0,
        1,
        5,
    };
    vector<int> sy = {2, 1, 1, 1};
    vector<int> tx = {
        5,
        2,
        2,
        350824,
    };
    vector<int> ty = {
        4,
        3,
        2,
        287008,
    };

    Solution sol;
    for (int i = 0; i < sx.size( ); ++i) {
        int res = sol.minMoves(sx[i], sy[i], tx[i], ty[i]);
        cout << res << endl;
    }
    return 0;
}
