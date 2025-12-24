#include <algorithm>
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
    int maxFrequency(vector<int> &nums, int k, int numOperations) {
        int mx = *max_element(nums.begin( ), nums.end( ));
        map<int, int> diff;
        map<int, int> freq;

        int n = nums.size( );
        for (int &i : nums) {
            freq[i]++;
            int l = max(i - k, 0);
            int r = min(i + k, mx);
            diff[l]++;
            diff[r + 1]--;
            diff[i] += 0; // for cumSum
        }

        int res = 1;
        int cumSum = 0;

        for (auto &[target, delta] : diff) {
            cumSum += delta;

            int currFq = freq[target];
            int opsReq = cumSum - currFq;
            int mxPossFq = min(opsReq, numOperations);

            res = max(res, currFq + mxPossFq);
        }

        return res;
    }
};

int main( ) {
    vector<vector<int>> nums = {
        {1, 4, 5},
        {5, 11, 20, 20},
        {999999997, 999999999, 999999999},
        {87145, 319704, 410063, 757659, 119255, 59894, 982258, 866920, 646385, 577226, 506033, 784827, 872669, 386189, 485391, 976460, 653997, 688066, 152062, 619791, 23338, 567801, 863638, 353972, 729577, 50873, 817617, 993487, 400027, 49249, 460914, 837206, 97256, 127106, 891532, 940815, 93276, 236972, 701951, 847579, 787803, 896208, 391438, 289512, 4433, 185315, 779877, 422739, 972569, 713107, 715559, 529063, 979015, 899495, 399401, 182813, 157389, 330335, 520092, 336238, 379110, 332445, 379835, 571827, 796060, 310224, 378769, 502453, 100561, 545301, 963231, 424750, 507463, 586376, 413429, 645322, 474697, 648148, 36234, 533049, 790426, 274912, 525062, 520921, 377247, 318689, 191995, 283346, 516280, 626754, 826012, 101215, 894364, 538738, 822988, 508452, 322453, 846624, 962117, 935864},
        {5, 64}
    };
    vector<int> k = {1, 5, 999999999, 51996, 42};
    vector<int> numOperations = {2, 1, 2, 46, 2};
    Solution sol;
    for (int i = 0; i < numOperations.size( ); i++) cout << sol.maxFrequency(nums[i], k[i], numOperations[i]) << endl;
    return 0;
}