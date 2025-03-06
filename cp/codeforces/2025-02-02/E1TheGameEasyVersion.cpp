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
    vector<int> w(n);
    for (int &i : w) cin >> i;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> in_mx;
    auto in_dfs = [&](auto &&self, int node, int par) -> void {
        in_mx[node] = w[node];

        for (int ch : adj[node]) {
            if (ch != par) {
                self(self, ch, node);
                in_mx[node] = max(in_mx[node], in_mx[ch]);
            }
        }
    };

    map<int, int> out_mx;
    auto out_dfs = [&](auto &&self, int node, int par) -> void {
        int mx1 = -1, mx2 = -1;

        for (int ch : adj[node]) {
            if (ch != par) {
                if (in_mx[ch] >= mx1)
                    mx2 = mx1, mx1 = in_mx[ch];
                else if (in_mx[ch] >= mx2)
                    mx2 = in_mx[ch];
            }
        }

        for (int ch : adj[node]) {
            if (ch != par) {
                int curr = mx1;
                if (mx1 == in_mx[ch]) curr = mx2;
                out_mx[ch] = max({out_mx[node], w[node], curr});
                self(self, ch, node);
            }
        }
    };

    in_dfs(in_dfs, 0, -1);
    out_mx[0] = 0;
    out_dfs(out_dfs, 0, -1);

    vector<pii> v;
    for (int i = 0; i < n; i++) v.push_back({w[i], i});
    sort(v.rbegin( ), v.rend( ));

    for (int i = 0; i < n; i++) {
        if (out_mx[v[i].second] > v[i].first) {
            cout << v[i].second + 1 << endl;
            return;
        }
    }

    cout << 0 << endl;
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
