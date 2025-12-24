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

    vector<vector<int>> adj(n + 1);
    vector<int> sub(n + 1);

    for (int i = 2; i <= n; i++) {
        int x; // boss
        cin >> x;
        adj[x].push_back(i);
    }

    auto dfs = [&](auto &&go, int node) -> int {
        int cnt = 0;
        for (auto it : adj[node]) {
            cnt += 1 + go(go, it);
        }
        return sub[node] = cnt;
    };

    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) cout << sub[i] << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
