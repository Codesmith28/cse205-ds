#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define pii pair<int, int>

class Solution {
  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        // code here
        vector<vector<pii>> adj(N);
        vector<int> res(N, INT_MAX);

        for (auto it : edges) {
            int a = it[0], b = it[1], c = it[2];
            adj[a].push_back({b, c});
        }

        // dijkstra:
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        res[0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int dist = curr.first, node = curr.second;
            if (dist > res[node]) continue;

            for (auto nei : adj[node]) {
                int nn = nei.first, wt = nei.second;
                if (res[nn] > wt + dist) {
                    res[nn] = wt + dist;
                    pq.push({res[nn], nn});
                }
            }
        }

        for (auto &it : res)
            if (it == INT_MAX) it = -1;
        return res;
    }
};

int main() {
    return 0;
}
