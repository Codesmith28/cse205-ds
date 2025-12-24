#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

const int N = 1e5 + 5;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve( ) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++)
        if (is_prime[i]) primes.push_back(i);
}

class Solution {
  public:
    long long splitArray(vector<int> &nums) {
        using ll = long long;
        ll n = nums.size( );
        sieve( );

        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            if (is_prime[i])
                sum_a += nums[i];
            else
                sum_b += nums[i];
        }

        return abs(sum_a - sum_b);
    }
};

int main( ) {
    // [2,3,4]
    // [-1,5,7,0]
    Solution sol;
    vector<vector<int>> nums = {
        {2, 3, 4},
        {-1, 5, 7, 0},
    };
    for (int i = 0; i < nums.size( ); i++) {
        cout << "Case #" << i + 1 << ": ";
        cout << sol.splitArray(nums[i]) << endl;
    }
    return 0;
}