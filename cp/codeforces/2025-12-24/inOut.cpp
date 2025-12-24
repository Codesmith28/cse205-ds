#include <algorithm>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class InOut {
  public:
    vector<int> inDP;
    vector<int> outDP;
    vector<vector<int>> &adj;

    void inDFS(int node, int par) {
        for (auto it : adj[node]) {
            if (it != par) {
                inDFS(it, node);
                // populaet inDP
                inDP[node] = max(inDP[node], 1 + inDP[it]);
            }
        }
    }

    void outDFS(int node, int par) {
        int mx1, mx2;
        mx1 = mx2 = -1;
        for (auto it : adj[node]) {
            if (it != par) {
                if (inDP[it] > mx1) { // update first max
                    mx2 = mx1;
                    mx1 = inDP[it];
                } else { // update second max
                    mx2 = max(mx2, inDP[it]);
                }
            }
        }
        for (int it : adj[node]) {
            if (it != par) {
                int use = (inDP[it] == mx1) ? mx2 : mx1;
                outDP[it] = 1 + max(outDP[it], 1 + use);
                outDFS(it, node);
            }
        }
    }

    InOut(vector<vector<int>> &adj, int fnode) : adj(adj) {
        int n = adj.size( );
        inDP.resize(n + 1, 0);
        outDP.resize(n + 1, 0);
        inDFS(fnode, -1);
        outDFS(fnode, -1);
    }
};

int main( ) {
    vector<vector<int>> adj = {
        {1, 2},
        {0},
        {0}
    };
    InOut solver(adj);
    return 0;
}
