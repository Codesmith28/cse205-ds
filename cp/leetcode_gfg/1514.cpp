#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define pdi pair<double, int>
#define pid pair<int, double>

class Solution {
  public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &prob, int start, int end) {
        vector<vector<pid>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back({b, prob[i]});
            adj[b].push_back({a, prob[i]});
        }

        vector<double> maxProb(n, 0);
        maxProb[start] = 1.0;

        priority_queue<pdi> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [currProb, currNode] = pq.top();
            pq.pop();

            for (auto &[nextNode, edgeProb] : adj[currNode]) {
                double newProb = currProb * edgeProb;
                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        return maxProb[end];
    }
};

int main() {
    return 0;
}
