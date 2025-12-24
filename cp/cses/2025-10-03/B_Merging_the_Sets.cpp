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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> who(m + 1); // list of sets containing x

    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            who[x].push_back(i);
        }
    }

    int cnt2 = 0;
    for (int x = 1; x <= m; x++) {
        if (who[x].size( ) == 0) {
            cout << "NO" << endl;
            return;
        }
        if (who[x].size( ) >= 3) {
            cout << "YES " << endl;
            return;
        }
        if (who[x].size( ) == 2) cnt2++;
    }

    if (cnt2 >= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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