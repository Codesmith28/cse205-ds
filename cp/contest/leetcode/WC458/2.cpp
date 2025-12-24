#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

// at most k connected components
// cost of component = max edge weight in that component
// if no edges in the component, cost is 0
// min possible value of maximum cost among k components

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
    int minCost(int n, vector<vector<int>> &edges, int k) {
        sort(edges.begin( ), edges.end( ), [&](auto &a, auto &b) {
            return a[2] < b[2];
        });

        vector<int> w;
        DSU dsu(n);
        for (auto &e : edges) {
            if (dsu.Union(e[0], e[1])) {
                w.push_back(e[2]);
            }
        }

        sort(w.rbegin( ), w.rend( ));

        int res = INT_MAX;
        for (int cuts = 0; cuts <= k - 1 && cuts < w.size( ); ++cuts) {
            res = min(res, cuts + 1 == n ? 0 : w[cuts]);
        }

        return res;
    }
};

int main( ) {
    vector<int> n = {5, 4, 4, 3};
    vector<vector<vector<int>>> edges = {
        {{0, 1, 4}, {1, 2, 3}, {1, 3, 2}, {3, 4, 6}},
        {{0, 1, 5}, {1, 2, 5}, {2, 3, 5}},
        {{0, 1, 5}, {1, 2, 5}, {2, 3, 5}},
        {{0, 1, 80}, {0, 2, 6}, {1, 2, 46}},
    };
    vector<int> k = {2, 1, 4, 1};
    Solution sol;
    for (int i = 0; i < n.size( ); i++) {
        cout << sol.minCost(n[i], edges[i], k[i]) << endl;
    }
    return 0;
}