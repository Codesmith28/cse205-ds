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
    int splitArray(vector<int> &nums, int k) {
        // subarrays => prefix
        int n = nums.size( );

        auto check = [&](int mid) -> pair<bool, int> {
            int piece = 0;
            int curr_sum = 0;
            int mx = 0;
            for (int i = 0; i < n; i++) {
                curr_sum += nums[i];
                if (curr_sum > mid) {
                    piece++;
                    curr_sum = nums[i];
                    mx = max(mx, curr_sum);
                }
            }
            piece++;
            return {piece <= k, mx};
        };

        int low = *min_element(nums.begin( ), nums.end( ));
        int high = accumulate(nums.begin( ), nums.end( ), 0);
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid).first) {
                res = check(mid).second;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};

// [7,2,5,10,8]
// 2
// [1,2,3,4,5]
// 2

int main( ) {
    vector<vector<int>> testCases = {
        {7, 2, 5, 10, 8},
        {1, 2, 3, 4,  5}
    };
    vector<int> k = {2, 2};
    Solution sol;
    for (int i = 0; i < testCases.size( ); i++) cout << sol.splitArray(testCases[i], k[i]) << endl;
    return 0;
}