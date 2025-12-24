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
    long long maximizeXorAndXor(vector<int> &nums) {
        using ll = long long;
        int n = nums.size( );
        ll ans = 0;
        int total = pow(3, n); // 3^n poss

        for (int mask = 0; mask < total; mask++) {
            ll xor_a = 0, and_b = -1, xor_c = 0;
            int curr = mask;

            for (int i = 0; i < n; ++i) {
                int group = curr % 3;
                curr /= 3;

                if (group == 0) {
                    xor_a ^= nums[i];
                } else if (group == 1) {
                    if (and_b == -1)
                        and_b = nums[i];
                    else
                        and_b &= nums[i];
                } else {
                    xor_c ^= nums[i];
                }
            }

            if (and_b == -1) and_b = 0;

            ans = max(ans, xor_a + and_b + xor_c);
        }

        return ans;
    }
};

int main( ) {
    Solution sol;
    vector<vector<int>> test_cases = {
        {2, 3},
        {1, 3, 2},
        {2, 3, 6, 7},
    };
    for (auto &nums : test_cases) {
        cout << sol.maximizeXorAndXor(nums) << endl;
    }
    return 0;
}
