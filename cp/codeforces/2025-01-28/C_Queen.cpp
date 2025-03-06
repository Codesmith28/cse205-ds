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
    map<int, set<int>> adj;

    int root = 0;

    for (int i = 1; i <= n; i++) {
        if (pc[i].first == -1)
            root = i;
        else
            adj[pc[i].first].insert(i);
    }

    vector<int> list;

    for (int i = 1; i <= n; i++) {
        if (i != root && pc[i].second == 1) {
            bool flag = true;
            for (int ch : adj[i]) {
                if (pc[ch].second == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                list.push_back(i);
            }
        }
    }

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
