#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &res) {
        res.push_back(node);
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, res);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, adj, vis, res);
        }

        return res;
    }
};

int main() {
    return 0;
}