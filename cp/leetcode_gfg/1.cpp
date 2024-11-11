#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
  public:
    long long maxScore(vector<int> &nums) {
        int n = nums.size( );

        ll gcd = nums[0];
        for (int i = 1; i < n; i++) {
            gcd = __gcd(gcd, (ll)nums[i]);
        }

        ll lcm = nums[0];
        for (int i = 1; i < n; i++) {
            lcm = (lcm * nums[i]) / __gcd(lcm, (ll)nums[i]);
        }

        ll mx = gcd * lcm;

        for (int i = 0; i < n; i++) {
            ll new_gcd = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                new_gcd = __gcd(new_gcd, (ll)nums[j]);
            }

            ll new_lcm = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                new_lcm = (new_lcm * nums[j]) / __gcd(new_lcm, (ll)nums[j]);
            }

            mx = max(mx, new_gcd * new_lcm);
        }

        return mx;
    }
};

int main( ) {
    vector<vector<int>> nums = {
        {2, 4, 8, 16},
        {1, 2, 3, 4, 5},
        {3},
        {2, 29},
    };

    Solution sol;
    for (auto &x : nums) {
        cout << sol.maxScore(x) << endl;
    }

    return 0;
}
