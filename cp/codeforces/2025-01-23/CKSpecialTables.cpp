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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> res(n, vector<int>(n, 0));
    vector<int> list(n * n);
    iota(list.begin( ), list.end( ), 1);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            res[i][j] = list[idx++];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = k - 1; j < n; j++) {
            res[i][j] = list[idx++];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += res[i][k - 1];
    cout << sum << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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
