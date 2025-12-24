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
        int countTrapezoids(vector<vector<int>> &points) {
                int n = points.size( );
                int res = 0;
                return res;

                map<string, int> paralle, collinear;
        }
};

int main( ) {
        vector<vector<vector<int>>> points = {
            {{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}},
            {{0, 0}, {1, 0}, {0, 1}, {2, 1}},
            {{-32, 12}, {-32, -94}, {-32, -15}, {-30, 88}},
            {{82, 7}, {82, -9}, {82, -52}, {82, 78}},
            {{71, -89}, {-75, -89}, {-9, 11}, {-24, -89}, {-51, -89}, {-77, -89}, {42, 11}},
        };
        Solution sol;
        for (auto &point : points) cout << sol.countTrapezoids(point) << endl;

        return 0;
}
