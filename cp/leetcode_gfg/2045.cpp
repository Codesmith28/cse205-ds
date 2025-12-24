#include <bits/stdc++.h>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>

class Solution {
  public:
    int secondMinimum(int n, vvi &edges, int time, int change) {
        vvi adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dj(n, adj, time, change);
    }

    int dj(int n, vvi &adj, int time, int change) {
        vi d1(n + 1, INT_MAX);
        vi d2(n + 1, INT_MAX);
        vi freq(n + 1);

        priority_queue<pii, vii, greater<pii>> pq;
        pq.push({0, 1});
        d1[1] = 0;

        while (!pq.empty()) {
            auto [timeTaken, node] = pq.top();
            pq.pop();

            freq[node]++;
            if (freq[node] == 2 && node == n) return timeTaken;

            if ((timeTaken / change) % 2) {
                timeTaken = change * (timeTaken / change + 1) + time;
            } else {
                timeTaken += time;
            }

            for (auto &nei : adj[node]) {
                if (freq[nei] == 2) continue;
                if (d1[nei] > timeTaken) {
                    d2[nei] = d1[nei];
                    d1[nei] = timeTaken;
                    pq.push({timeTaken, nei});
                } else if (d2[nei] > timeTaken && d1[nei] != timeTaken) {
                    d2[nei] = timeTaken;
                    pq.push({timeTaken, nei});
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<vvi> edges = {
        {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}}
    };
    vector<int> time = {3};
    vector<int> change = {5};

    for (int i = 0; i < time.size(); i++) {
        cout << s.secondMinimum(5, edges[i], time[i], change[i]) << endl;
    }
    return 0;
}