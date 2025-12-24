#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPartitionsAfterOperations(string s, int k) {
        using ll = long long;
        int n = s.size( );

        // dp[i][mask][canChange] = best result from index i
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(1 << 10, vector<int>(2, -1))); // cannot store this big inside vector!

        map<ll, ll> dp;
        // key = {idx}{mask}{canChange} bits in binary
        // value = res at {idx}{mask}{canChange}

        auto solve = [&](auto &&go, int i, int mask, bool canChange) -> int {
            ll key = canChange | (mask << 1) | (i << 27);
            if (dp.count(key)) return dp[key];

            if (i == n) return 0;
            int res = 0;

            int c = s[i] - 'a';
            int newMask = mask | (1 << c);
            int distinct = __builtin_popcount(newMask);

            // Case 1: Keep s[i]
            if (distinct > k)
                res = 1 + go(go, i + 1, 1 << c, canChange);
            else
                res = go(go, i + 1, newMask, canChange);

            // Case 2: Change s[i] (if allowed)
            if (canChange) {
                for (int a = 0; a < 26; a++) {
                    int altMask = mask | (1 << a);
                    int cnt = __builtin_popcount(altMask);
                    int cur;
                    if (cnt > k)
                        cur = 1 + go(go, i + 1, 1 << a, false);
                    else
                        cur = go(go, i + 1, altMask, false);
                    res = max(res, cur);
                }
            }

            return dp[key] = res;
        };

        return solve(solve, 0, 0, true) + 1;
    }
};

int main( ) {
    vector<string> s = {
        "accca",
        "aabaab",
        "xxyz",
    };
    vector<int> k = {
        2,
        3,
        1,
    };
    Solution sol;
    for (int i = 0; i < k.size( ); i++) {
        cout << sol.maxPartitionsAfterOperations(s[i], k[i]) << endl;
    }
    return 0;
}