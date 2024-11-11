#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define pii pair<int, int>

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) {
        // code here
        vector<vector<pii>> adj(N);

        for (auto it : edges) {
            int a = it[0], b = it[1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }

        vector<int> res(N, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        res[src] = 0;

        // dj:
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int dist = curr.first, node = curr.second;
            if (dist > res[node]) continue;

            for (auto n : adj[node]) {
                int wt = n.second, nei = n.first;
                if (res[nei] > wt + dist) {
                    res[nei] = wt + dist;
                    pq.push({res[nei], nei});
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