#include <bits/stdc++.h>
#include <pthread.h>
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
    int n, q;
    cin >> n >> q;
    char x;
    vector<vector<int>> forest(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            forest[i][j] = (x == '*' ? 1 : 0);
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int up = pref[i - 1][j];
            int left = pref[i][j - 1];
            int diag = pref[i - 1][j - 1];
            pref[i][j] = up + left - diag + (forest[i - 1][j - 1] == 1 ? 1 : 0);
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int trees = pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
        cout << trees << endl;
    }
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
