#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int subsequence_pair_count(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        int max_elem = *max_element(nums.begin( ), nums.end( ));
        unordered_map<int, long long> gcd_count;

        for (int num : nums) {
            unordered_map<int, long long> new_gcd_count;
            new_gcd_count[num]++;

            for (auto &[g, count] : gcd_count) {
                int new_gcd = gcd(g, num);
                new_gcd_count[new_gcd] = (new_gcd_count[new_gcd] + count) % MOD;
            }

            for (auto &[g, count] : new_gcd_count) {
                gcd_count[g] = (gcd_count[g] + count) % MOD;
            }
        }

        int pair_count = 0;
        for (auto &[g, count] : gcd_count) {
            pair_count = (pair_count + count * (count - 1) % MOD) % MOD;
        }

        return pair_count;
    }
};

int main( ) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.subsequence_pair_count(nums) << endl;
    return 0;
}
