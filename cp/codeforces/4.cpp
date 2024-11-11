#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int mod = 1e9 + 7;

    int countBalancedPermutations(string num) {
        vector<int> fq(10, 0);
        for (char c : num) fq[c - '0']++;

        int n = num.size( );
        vector<vector<vector<int>>> dp(721, vector<vector<int>>(721, vector<int>(n + 1, -1)));

        auto recur = [&](auto &&self, int s1, int s2, int rem) -> int {
            if (rem == 0) return s1 == s2;
            if (dp[s1][s2][rem] != -1) return dp[s1][s2][rem];

            int cnt = 0;
            for (int digit = 0; digit < 10; ++digit) {
                if (fq[digit] > 0) {
                    fq[digit]--;
                    if ((n - rem) % 2 == 0) {
                        cnt = (cnt + self(self, s1 + digit, s2, rem - 1)) % mod;
                    } else {
                        cnt = (cnt + self(self, s1, s2 + digit, rem - 1)) % mod;
                    }
                    fq[digit]++;
                }
            }

            return dp[s1][s2][rem] = cnt;
        };

        return recur(recur, 0, 0, n);
    }
};

int main( ) {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.countBalancedPermutations(s) << endl;
    return 0;
}
