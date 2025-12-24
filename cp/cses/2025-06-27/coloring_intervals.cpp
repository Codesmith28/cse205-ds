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
    vector<vector<int>> inv(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        cin >> inv[i][0] >> inv[i][1];
        inv[i][2] = i;
    }
    sort(inv.begin( ), inv.end( ));

    int flag = 0, right = 0;
    vector<int> res(n, 0);

    for (auto it : inv) {
        int l = it[0], r = it[1], idx = it[2];
        if (l > right) { // not contained
            flag = 0;
            res[idx] = flag;
            right = r;
        } else { // contained
            res[idx] = !flag;
            if (right < r) { // partially contained
                flag = !flag;
                right = r;
            }
        }
    }

    for (int i : res) cout << i;
    cout << endl;
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
