#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vvii vector<vector<pii>>

class Solution {
  public:
    int finder(int n, vvi &spat, int thres) {
        int city = -1, min = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reach = 0;
            for (int j = 0; j < n; j++) {
                if (spat[i][j] <= thres and i != j) reach++;
            }

            if (reach <= min) {
                min = reach;
                city = i;
            }
        }

        return city;
    }

    void dj(vvii &adj, vi &spath, int src) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});

        spath[src] = 0;
        while (!pq.empty()) {
            auto [cdis, ccity] = pq.top();
            pq.pop();
            if (cdis > spath[ccity]) continue;

            for (const auto &[nei, wt] : adj[ccity]) {
                if (spath[nei] > cdis + wt) { // if new path is shorter:
                    spath[nei] = cdis + wt;
                    pq.push({spath[nei], nei});
                }
            }
        }
    }

    int findTheCity(int n, vvi &edges, int thres) {
        vvii adj(n);
        vvi spath(n, vi(n, INT_MAX));

        for (int i = 0; i < n; i++) spath[i][i] = 0;
        for (auto it : edges) {
            int a = it[0], b = it[1], c = it[2];
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        for (int i = 0; i < n; i++) {
            dj(adj, spath[i], i);
        }

        return finder(n, spath, thres);
    }
};

int main() {
    vector<vector<vector<int>>> edges = {
        {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}},
        {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}},
    };
    vi n = {5, 4};
    vi threshold = {2, 4};

    Solution s;
    for (int i = 0; i < n.size(); i++) {
        cout << s.findTheCity(n[i], edges[i], threshold[i]) << endl;
    }

    return 0;
}
