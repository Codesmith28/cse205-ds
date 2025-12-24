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
    vector<int> findCoins(vector<int> &ways) {
        int n = ways.size( );
        set<int> coins;

        for (int i = 0; i < n; i++) {
            // check for ways = 1   ;
            int curr = 0;
            if (ways[i] == 1) {
                coins.insert(i + 1);
                curr = i + 1;
            } else {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                int nxt = j + 1;
                if (nxt - curr >= 0) ways[j] -= ways[j - (curr - 1)];
                // if(j - curr >= 0) ways[j] -= ways[j - curr];
            }
        }

        return vector<int>(coins.begin( ), coins.end( ));
    }
};

// [0,1,0,2,0,3,0,4,0,5]
// [1,2,2,3,4]
// [1,2,3,4,15]

int main( ) {
    Solution sol;
    vector<vector<int>> testCases = {
        {0, 1, 0, 2, 0, 3, 0, 4, 0, 5},
        {1, 2, 2, 3, 4},
        {1, 2, 3, 4, 15}
    };
    for (int i = 0; i < testCases.size( ); i++) {
        vector<int> res = sol.findCoins(testCases[i]);
        cout << "Test Case " << i + 1 << ": ";
        for (int r : res) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}