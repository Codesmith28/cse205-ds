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
    int minimumIncrements(vector<int> &nums, vector<int> &target) {
        sort(nums.begin( ), nums.end( ));
        // lcm of all elements in target

        int i = 1;
        for (int x : target) {
            i = lcm(i, x);
        }

        int mnn = INT_MAX;

        // Find the minimum positive difference by checking elements from both arrays
        auto it = lower_bound(nums.begin( ), nums.end( ), i + 1); // Find strictly greater element
        if (it != nums.end( )) {
            if (i - *it < 0) {
            } else {
                mnn = min(mnn, i - *it);
            }
        }

        return (mnn == INT_MAX) ? 0 : mnn; // Return -1 if no valid positive difference is found
    }
};

int main( ) {
    vector<vector<int>> ip = {
        {1, 2, 3},
        {8, 4},
        {7, 9, 10},
    };
    vector<vector<int>> op = {
        {4},
        {10, 5},
        {7}
    };
    Solution s;
    for (int i = 0; i < ip.size( ); i++) {
        cout << s.minimumIncrements(ip[i], op[i]) << endl;
    }
    return 0;
}
