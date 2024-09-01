#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);

        auto dfs = [&](int node, int parent, auto &&dfs) -> bool {
            vis[node] = true;

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    if (dfs(it, node, dfs)) return true;
                } else if (it != parent) {
                    return true;
                }
            }

            return false;
        };

        for (int i = 0; i < V; i++) {
            if (!vis[i] and dfs(i, -1, dfs)) return true;
        }

        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
