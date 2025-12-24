#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;

#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p) cin >> i;
    string s;
    cin >> s;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++) {
        adj[p[i]].push_back(i + 1);
    }

    vector<vector<int>> joint;
    vector<bool> vis(n + 1, false);

    auto dfs = [&](int node, vector<int> &comp, auto &&dfs) -> void {
        vis[node] = true;
        comp.push_back(node);

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, comp, dfs);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, comp, dfs);
            joint.push_back(comp);
        }
    }

    vector<int> res(n);
    for (auto comp : joint) {
        int sum = 0;
        for (int node : comp) {
            if (s[node - 1] == '0') {
                sum++;
            }
        }
        for (int node : comp) {
            res[node - 1] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
