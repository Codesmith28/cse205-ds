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
    using pii = pair<int, int>;
    int maxWeight(int n, vector<vector<int>> &edges, int k, int t) {
        vector<vector<pii>> adj(n);
        for (auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].emplace_back(v, w);
        }

        vector<vector<set<int>>> dp(n, vector<set<int>>(k + 1, set<int>( )));
        for (int i = 0; i < n; i++) dp[i][0].insert(0);

        for (int e = 0; e < k; e++) {         // for all k edges
            for (int u = 0; u < n; u++) {     // for all nodes
                for (auto [v, w] : adj[u]) {  // for all its neighbors
                    for (int it : dp[u][e]) { // for all existing edges, add edge with weight w if sum < t
                        if (it + w < t) dp[v][e + 1].insert(it + w);
                    }
                }
            }
        }

        int res = -1;
        for (int u = 0; u < n; u++) { // for all nodes
            if (!dp[u][k].empty( )) {
                res = max(res, *dp[u][k].rbegin( ));
            }
        }

        return res;
    }
};

int main( ) {
    vector<int> n = {
        3,
        3,
        3,
    };
    vector<vector<vector<int>>> edges = {
        {{0, 1, 1}, {1, 2, 2}},
        {{0, 1, 2}, {0, 2, 3}},
        {{0, 1, 6}, {1, 2, 8}},
    };
    vector<int> k = {
        2,
        1,
        1,
    };
    vector<int> t = {
        4,
        3,
        6,
    };
    for (int i = 0; i < n.size( ); i++) {
        Solution sol;
        cout << sol.maxWeight(n[i], edges[i], k[i], t[i]) << endl;
    }
    return 0;
}