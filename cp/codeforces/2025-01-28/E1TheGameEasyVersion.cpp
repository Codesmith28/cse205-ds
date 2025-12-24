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
#define piv  pair<int, vector<int>>

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int &i : w) cin >> i;

    map<int, vector<int>> adj;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> in, out;

    // max value of inside subtree rooted at node
    auto indfs = [&](auto &&self, int node, int par) -> void {
        in[node] = w[node];
        for (int ch : adj[node]) {
            if (ch != par) {
                self(self, ch, node);
                in[node] = max(in[node], in[ch]);
            }
        }
    };

    // max value of outside subtree rooted at node
    auto outdfs = [&](auto &&self, int node, int par) -> void {
        multiset<int> chs;
        for (int ch : adj[node]) {
            if (ch != par) {
                chs.insert(in[ch]);
            }
        }
        for (int ch : adj[node]) {
            if (ch != par) {
                chs.erase(chs.find(in[ch]));
                int v1 = w[node];
                int v2 = out[node];
                int v3 = chs.empty( ) ? 0 : *chs.rbegin( );
                out[ch] = max({v1, v2, v3});
                chs.insert(in[ch]);

                self(self, ch, node);
            }
        }
    };

    indfs(indfs, 0, -1);
    outdfs(outdfs, 0, -1);

    pii res = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (out[i] > w[i]) {
            res = max(res, {w[i], i});
        }
    };

    cout << res.second + 1 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
