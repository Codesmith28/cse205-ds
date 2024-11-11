#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            int mx = 0;

            int lob = max(0, curr - k);
            int upb = min(25, curr + k);
            for (int j = lob; j <= upb; ++j) mx = max(mx, dp[j]);

            dp[curr] = mx + 1;
            res = max(res, dp[curr]);
        }

        return res;
    }
};

int main() {
    int k;
    string s;
    cin >> s;
    cin >> k;

    Solution sol;
    cout << sol.longestIdealString(s, k) << endl;
    return 0;
}