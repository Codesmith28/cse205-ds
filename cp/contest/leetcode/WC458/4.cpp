#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    int maxLen(int n, vector<vector<int>> &edges, string label) {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // mask -> path from [i, j] ; dp[mask][i][j] -> whether path [i, j] pallin or not
        vector<vector<vector<int>>> dp(1 << n, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

        /// base case:
        for (int i = 0; i < n; i++) dp[1 << i][i][i] = 1; // all nodes are pallindromic solo:
        for (int i = 0; i < n; i++) {                     // edges where both nodes have same label:
            int node = i;
            for (int it : adj[node]) {
                if (label[node] == label[it]) {
                    dp[(1 << node) | (1 << it)][node][it] = 1;
                }
            }
        }

        int res = 0;

        // expand the mask:
        for (int mask = 1; mask < (1 << n); mask++) { // all poss paths
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) continue; // if i is not in mask, skip
                for (int j = 0; j < n; j++) {
                    if (mask && (1 << j) == 0) continue; // if j is not in mask, skip
                    if (!dp[mask][i][j]) continue;       // if path [i, j] is not pallindromic, skip

                    // current path is pallin:
                    res = max(res, __builtin_popcount(mask)); // update max length

                    // expand from both ends:
                    for (int it : adj[i]) {
                        if (mask && (1 << it)) continue;
                        for (int jt : adj[j]) {
                            if (mask & (1 << jt)) continue;
                            if (it == jt) continue;
                            if (label[it] != label[jt]) continue;
                            dp[mask | (1 << it) | (1 << jt)][it][jt] = 1; // mark new path
                        }
                    }
                }
            }
        }

        return res;
    }
};

int main( ) {
    vector<int> n = {3, 3, 4, 3};
    vector<vector<vector<int>>> edges = {
        {{0, 1}, {1, 2}},
        {{0, 1}, {0, 2}},
        {{0, 2}, {0, 3}, {3, 1}},
        {{0, 1}, {2, 1}, {0, 2}},
    };
    vector<string> labels = {"aba", "abc", "bbac", "hjj"};
    Solution sol;
    for (int i = 0; i < n.size( ); i++) {
        cout << sol.maxLen(n[i], edges[i], labels[i]) << endl;
    }
    return 0;
}
