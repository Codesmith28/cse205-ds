#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
using pii = pair<int, int>;

class Solution {
  public:
    int minTime(int n, vector<vector<int>> &edges) {
        vector<vector<array<int, 3>>> adj(n); // adj[u] = {v, st, en}
        for (auto &it : edges) {
            int u = it[0], v = it[1], st = it[2], en = it[3];
            adj[u].push_back({v, st, en});
        }

        vector<int> spath(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, 0}); // {curr_time, node}
        spath[0] = 0;

        while (!pq.empty( )) {
            auto [curr_time, u] = pq.top( );
            pq.pop( );
            if (curr_time > spath[u]) continue;

            for (auto &[v, st, en] : adj[u]) {
                if (curr_time > en) continue;
                int nxt = max(curr_time, st) + 1; // wait until st if needed
                if (nxt < spath[v]) {
                    spath[v] = nxt;
                    pq.push({nxt, v});
                }
            }
        }

        return spath[n - 1] == INT_MAX ? -1 : spath[n - 1];
    }
};

int main( ) {
    vector<int> n = {3, 4, 3};
    vector<vector<vector<int>>> edges = {
        {{0, 1, 0, 1}, {1, 2, 2, 5}},
        {{0, 1, 0, 3}, {1, 3, 7, 8}, {0, 2, 1, 5}, {2, 3, 4, 7}},
        {{1, 0, 1, 3}, {1, 2, 3, 5}},
    };

    Solution sol;
    for (int i = 0; i < n.size( ); i++) {
        int ans = sol.minTime(n[i], edges[i]);
        cout << ans << endl;
    }

    return 0;
}
