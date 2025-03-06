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
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<pii> pc(n + 1);
    for (int i = 1; i <= n; i++) cin >> pc[i].first >> pc[i].second;
    map<int, bool> vis;

    map<int, set<int>> adj;
    int root = 0;

    for (int i = 1; i <= n; i++) {
        adj[pc[i].first].insert(i);
        if (pc[i].first == -1) root = i;
    }

    vector<int> list;

    auto dfs = [&](auto &&self, int node, int par) -> void {
        bool m = pc[node].second == 1;
        int sub = 0, net = 0;
        vector<int> children;
        for (int ch : adj[node]) {
            if (ch != par) {
                sub += (pc[ch].second == 1);
                net++;
                children.push_back(ch);
            }
        }

        if (m) {
            if (sub == net) { // remove node
                if (!vis[node]) {
                    list.push_back(node);
                    vis[node] = true;
                }
                for (int ch : children) adj[par].insert(ch);
                adj.erase(node);
                for (int ch : children) self(self, ch, par);
            } else { // don't remove node
                for (int ch : children) self(self, ch, node);
            }
        } else {
            for (int ch : children) self(self, ch, node);
        }
    };

    dfs(dfs, root, -1);

    if (list.size( ) == 0) {
        cout << -1 << endl;
    } else {
        sort(list.begin( ), list.end( ));
        for (int i : list) cout << i << " ";
        cout << endl;
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
