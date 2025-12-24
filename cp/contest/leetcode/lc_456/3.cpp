#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

int minimumMaxXOR(vector<int> &nums, int k) {
    int n = nums.size( );
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] ^ nums[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int m = 0; m < i; ++m) {
                int xr = prefix[i] ^ prefix[m];
                dp[i][j] = min(dp[i][j], max(dp[m][j - 1], xr));
            }
        }
    }

    return dp[n][k];
}

int main( ) {
    // [1,2,3]
    // 2
    // [2,3,3,2]
    // 3
    // [1,1,2,3,1]
    // 2
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {2, 3, 3, 2},
        {1, 1, 2, 3, 1}
    };
    vector<int> kValues = {2, 3, 2};
    for (int i = 0; i < testCases.size( ); ++i) {
        vector<int> nums = testCases[i];
        int k = kValues[i];
        int result = minimumMaxXOR(nums, k);
        cout << "Minimum maximum XOR for case " << i + 1 << ": " << result << endl;
    }
    return 0;
}