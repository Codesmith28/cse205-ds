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
            if (Rank[xset] < Rank[yset]) {
                Parent[xset] = yset;
            } else {
                Parent[yset] = xset;
                if (Rank[xset] == Rank[yset]) Rank[xset]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
  public:
    vector<int> processQueries(int c, vector<vector<int>> &conn, vector<vector<int>> &queries) {
        DSU dsu(c + 1);
        for (auto &edge : conn) {
            dsu.Union(edge[0], edge[1]);
        }

        map<int, set<int>> grid;
        for (int i = 1; i <= c; ++i) {
            int root = dsu.Find(i);
            grid[root].insert(i);
        }

        vector<bool> online(c + 1, true);
        vector<int> res;

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.Find(x);
            if (type == 1) {
                if (online[x]) {
                    res.push_back(x);
                } else {
                    if (grid[root].empty( )) {
                        res.push_back(-1);
                    } else {
                        res.push_back(*grid[root].begin( ));
                    }
                }
            } else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    grid[root].erase(x);
                }
            }
        }

        return res;
    }
};

int main( ) {
    vector<int> c = {
        5,
        3,
    };
    vector<vector<vector<int>>> conn = {
        {{1, 2}, {2, 3}, {3, 4}, {4, 5}},
        {}
    };
    vector<vector<vector<int>>> queries = {
        {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}},
        {{1, 1}, {2, 1}, {1, 1}},
    };
    Solution sol;
    for (int i = 0; i < c.size( ); ++i) {
        vector<int> result = sol.processQueries(c[i], conn[i], queries[i]);
        cout << "Result for case " << i + 1 << ": ";
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
