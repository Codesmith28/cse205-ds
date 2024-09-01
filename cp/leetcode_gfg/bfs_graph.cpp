#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> res;
    queue<int> q;
    q.push(0);

    vector<bool> vis(V, false);
    vis[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
    }

    return res;
}

int main() {
    return 0;
}