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
    int minOperations(vector<int> &nums) {
        int res = 0;
        int n = nums.size( );
        set<int> vis;
        stack<int> st;

        for (int i : nums) {
            if (i == 0) {
                while (!st.empty( )) {
                    vis.erase(st.top( ));
                    st.pop( );
                }
                continue;
            }
            while (!st.empty( ) && st.top( ) > i) {
                vis.erase(st.top( ));
                st.pop( );
            }
            if (!vis.count(i)) {
                res++;
                vis.insert(i);
            }
            st.push(i);
        }

        return res;
    }
};

// [0,2]
// [3,1,2,1]
// [1,2,1,2,1,2]

int main( ) {
    vector<vector<int>> nums = {
        {0, 2},
        {3, 1, 2, 1},
        {1, 2, 1, 2, 1, 2},
        {1, 2, 1, 2, 1, 3, 2, 3, 2, 3},
    };
    Solution sol;
    for (auto &v : nums) cout << sol.minOperations(v) << endl << endl;
    return 0;
}