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
    string findOrder(string dict[], int n, int k) {
        map<char, vector<char>> adj;
        map<char, int> indeg;

        for (int i = 0; i < n; i++) {
            for (char c : dict[i]) indeg[c] = 0;
        }

        auto dj = [&](int src, vector<int> &spath) -> void {
            using pii = pair<int, int>;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, src});
            spath[src] = 0;

            while (!pq.empty( )) {
                auto [curr_dis, curr_node] = pq.top( );
                pq.pop( );

                if (spath[curr_node] < curr_dis) continue;
                for (auto it : adj[curr_node]) {
                    int nei = it[0], dis = it[1];
                    if (spath[nei] > curr_dis + dis) {
                        spath[nei] = curr_dis + dis;
                        pq.push({spath[nei], nei});
                    }
                }
            }
        };

        // update indegree:
        auto recur = [&](auto &&self, string a, string b, int i) -> void {
            if (i >= a.size( ) || i >= b.size( )) return;
            if (a[i] != b[i]) {
                adj[a[i]].push_back(b[i]);
                indeg[b[i]]++;
                return;
            }
            return self(self, a, b, i + 1);
        };

        // update indegree:
        for (int i = 0; i < n - 1; i++) recur(recur, dict[i], dict[i + 1], 0);

        // topological sort:
        queue<char> q;
        for (auto &p : indeg)
            if (p.second == 0) q.push(p.first);
        string res = "";

        while (!q.empty( )) {
            char curr = q.front( );
            q.pop( );
            res += curr;

            for (char c : adj[curr]) {
                indeg[c]--;
                if (indeg[c] == 0) q.push(c);
            }
        }

        return (res.size( ) == k) ? res : "";
    }
};

int main( ) {
    int sz = 1;
    return 0;
}