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
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    // store the suffix sum of 1s for each rows:
    multiset<int> suff;
    int r = 0;
    for (auto it : a) {
        int m = it.size( );
        int cnt = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (it[i] == 1) {
                cnt++;
            } else {
                break;
            }
        }
        if (cnt != 0) suff.insert(cnt);
    }

    if (suff.empty( )) {
        cout << 1 << endl;
        return;
    }

    int mex = 1;
    for (auto it : suff) {
        if (it >= mex) {
            mex++;
        } else {
            continue;
        }
    }

    cout << min(n, mex) << endl;
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
