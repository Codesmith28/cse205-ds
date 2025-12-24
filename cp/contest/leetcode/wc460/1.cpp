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
    long long maximumMedianSum(vector<int> &nums) {
        using ll = long long;
        sort(nums.begin( ), nums.end( ));
        // dbg(nums);
        int n = nums.size( ) / 3;
        ll sum = 0;
        for (int i = nums.size( ) - 2; n > 0; i -= 2, n--) {
            sum += nums[i];
        }
        return sum;
    }
};

int main( ) {
    Solution sol;
    vector<vector<int>> testCases = {
        {2, 1, 3,  2,  1,  3 },
        {1, 1, 10, 10, 10, 10}
    };
    for (auto &testCase : testCases) {
        cout << sol.maximumMedianSum(testCase) << endl;
    }
    return 0;
}