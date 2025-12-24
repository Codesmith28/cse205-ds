#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class DSU {
  public:
    vector<int> Parent, Rank;

    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }

    int Find(int x) {
        if (Parent[x] != x) Parent[x] = Find(Parent[x]);
        return Parent[x];
    }

    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};

class Solution {
  public:
    int minTime(int n, vector<vector<int>> &edges, int k) {
        int low = 0, high = 0;
        for (auto &e : edges) high = max(high, e[2]);

        auto valid = [&](int t) -> bool {
            DSU dsu(n);
            for (auto &e : edges) {
                int u = e[0], v = e[1], time = e[2];
                if (time > t) {
                    dsu.Union(u, v);
                }
            }
            set<int> comps;
            for (int i = 0; i < n; i++) comps.insert(dsu.Find(i));
            return comps.size( ) >= k;
        };

        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (valid(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main( ) {
    vector<int> n = {2, 3, 3};
    vector<vector<vector<int>>> edges = {
        {{0, 1, 3}},
        {{0, 1, 2}, {1, 2, 4}},
        {{0, 2, 5}}
    };
    vector<int> k = {2, 3, 2};
    Solution sol;
    for (int i = 0; i < n.size( ); ++i) {
        int res = sol.minTime(n[i], edges[i], k[i]);
        cout << "Case #" << i + 1 << ": " << res << endl;
    }
    return 0;
}