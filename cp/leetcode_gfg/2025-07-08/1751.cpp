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
    int maxValue(vector<vector<int>> &events, int k) {
        sort(events.begin( ), events.end( ), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        int n = events.size( );

        auto bs = [&](int target) -> int {
            int l = 0, r = n;
            int res = 0;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (events[mid][0] <= target) {
                    res = mid + 1;
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return res;
        };

        vector<vector<int>> dp(k + 1, vector<int>(n, -1));

        auto dfs = [&](auto &&go, int idx, int cnt) -> int {
            if (cnt == 0 || idx == n) return 0;
            if (dp[cnt][idx] != -1) return dp[cnt][idx];
            int nxt = bs(events[idx][1]); // immediate next event that starts after the current one ends
            int skip = go(go, idx + 1, cnt);
            int take = events[idx][2] + go(go, nxt, cnt - 1);
            return dp[cnt][idx] = max(skip, take);
        };

        return dfs(dfs, 0, k);
    }
};

int main( ) {
    vector<vector<vector<int>>> events = {
        {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}},
        {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}},
        {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}},
        {{53, 76, 2}, {24, 33, 70}, {59, 89, 72}, {47, 79, 52}, {50, 80, 4}, {20, 66, 9}, {59, 81, 45}, {40, 78, 12}, {34, 97, 62}, {29, 82, 62}, {78, 100, 9}, {20, 31, 9}, {17, 39, 7}, {21, 51, 75}, {80, 88, 71}, {69, 92, 34}},
    };
    vector<int> k = {2, 2, 3, 15};
    Solution sol;
    for (int i = 0; i < events.size( ); ++i) cout << sol.maxValue(events[i], k[i]) << endl;
    return 0;
}