#include <bits/stdc++.h>
#include <vector>
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
        using ll = long long;

        int n;
        ll k;
        vector<bool> online;
        vector<vector<pii>> graph;

        bool check(int mid) {
                map<int, int> indeg;
                vector<vector<pii>> adj(n);
                for (int u = 0; u < n; u++) {
                        for (auto [v, c] : graph[u]) {
                                if (c >= mid) {
                                        adj[u].emplace_back(v, c);
                                        indeg[v]++;
                                }
                        }
                }

                vector<int> s_arr;
                auto topo_sort = [&]( ) -> bool {
                        queue<int> q; // queue of nodes;
                        for (int i = 0; i < n; i++)
                                if (indeg[i] == 0) q.push(i);

                        while (!q.empty( )) {
                                int node = q.front( );
                                q.pop( );
                                s_arr.push_back(node);
                                for (auto [v, c] : adj[node]) {
                                        indeg[v]--;
                                        if (indeg[v] == 0) q.push(v);
                                }
                        }

                        return s_arr.size( ) == n;
                };

                if (!topo_sort( )) return false;

                vector<ll> dp(n, 1e18);
                dp[0] = 0;
                for (int node : s_arr) {
                        if (dp[node] == 1e18) continue;
                        for (auto [v, c] : adj[node]) {
                                if (v == n - 1 || online[v]) {
                                        dp[v] = min(dp[v], dp[node] + c);
                                }
                        }
                }

                return dp[n - 1] <= k;
        }

        int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k) {
                this->n = online.size( );
                this->online = online;
                this->graph.assign(n, { });
                this->k = k;

                for (auto it : edges) {
                        int u = it[0], v = it[1], c = it[2];
                        graph[u].emplace_back(v, c);
                }

                int left = 0, right = 1e9, res = -1;
                while (left <= right) {
                        int mid = left + (right - left) / 2;
                        if (check(mid)) { // max of mins
                                left = mid + 1;
                                res = mid;
                        } else {
                                right = mid - 1;
                        }
                }

                return res;
        }
};

int main( ) {
        Solution sol;
        vector<vector<vector<int>>> edges = {
            {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}},
            {{0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3, 4, 2}, {2, 4, 6}},
        };
        vector<vector<bool>> online = {
            {true, true, true, true},
            {true, true, true, false, true},
        };
        vector<long long> k = {10, 12};
        for (int i = 0; i < edges.size( ); i++) {
                cout << sol.findMaxPathScore(edges[i], online[i], k[i]) << endl;
        }
        return 0;
}