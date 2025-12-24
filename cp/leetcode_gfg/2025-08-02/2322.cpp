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
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size( );
        vector<vector<int>> adj(n);
        for (auto it : edges) {
        }
    }
};

int main( ) {
    Solution sol;
    vector<vector<int>> nums = {
        {1, 5, 5, 4, 11},
        {5, 5, 2, 4, 4, 2},
        {29, 29, 23, 32, 17},
    };
    vector<vector<vector<int>>> edges = {
        {{0, 1}, {1, 2}, {1, 3}, {3, 4}},
        {{0, 1}, {1, 2}, {5, 2}, {4, 3}, {1, 3}},
        {{3, 1}, {2, 3}, {4, 1}, {0, 4}},
    };
    for (int i = 0; i < nums.size( ); i++) {
        cout << sol.minimumScore(nums[i], edges[i]) << endl;
    }
    return 0;
}
