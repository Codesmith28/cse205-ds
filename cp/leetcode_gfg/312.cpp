#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int maxCoins(vector<int> &nums) {
        vector<int> a = {1};
        for (int &i : nums) a.push_back(i);
        a.push_back(1);

        int n = a.size( );

        vector<vector<int>> memo(n, vector<int>(n, 0));

        for (int len = 1; len <= n - 2; len++) {
            for (int left = 1; left <= n - len - 1; left++) {
                int right = left + len - 1;
                for (int idx = left; idx <= right; idx++) {
                    int coins = a[left - 1] * a[idx] * a[right + 1];
                    coins += memo[left][idx - 1] + memo[idx + 1][right];
                    memo[left][right] = max(memo[left][right], coins);
                }
            }
        }

        return memo[1][n - 2];
    }
};

int main( ) {
    vector<vector<int>> nums = {
        {3, 1, 5, 8},
        {1, 5},
    };

    Solution sol;
    for (auto &n : nums) cout << sol.maxCoins(n) << endl;
    return 0;
}
