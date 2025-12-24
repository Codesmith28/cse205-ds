#include <algorithm>
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n;
    cin >> n;
    vector<int> val(n);
    for (int &i : val) cin >> i;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subSum(n, 0);
    vector<int> cost(n, 0);

    // for subtree sum
    // cost = SUM(dist * val)
    // dist(i, v) -> given by depth
    int root = 0;
    auto preDFS = [&](auto &&go, int node, int par, int depth) -> void {
        subSum[node] = val[node];
        cost[root] += depth * val[node];
        for (int it : adj[node]) {
            if (it != par) {
                go(go, it, node, depth + 1);
                subSum[node] += subSum[it];
            }
        }
    };

    preDFS(preDFS, root, -1, 0);
    int netSum = subSum[root]; // sum of all vals in the tree

    // if we move the root from p -> c
    // inside c'subtree [subSum] ->  nodes closer by 1 => cost -= subSum[child]
    // outide c'subtree [netSum - subSum] -> nodes farther by 1 => cost += (netSum - subSum[child])
    auto dfs = [&](auto &&go, int node, int par) -> void {
        for (auto it : adj[node]) {
            if (it != par) {
                cost[it] = cost[node] - (subSum[it]) + (netSum - subSum[it]);
                go(go, it, node);
            }
        }
    };

    dfs(dfs, root, -1);
    cout << *max_element(cost.begin( ), cost.end( )) << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}