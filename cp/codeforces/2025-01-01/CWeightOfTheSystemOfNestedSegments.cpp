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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> xw(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> xw[i][0] >> xw[i][1];
        xw[i][2] = i + 1;
    }

    sort(xw.begin( ), xw.end( ), [&](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    xw.resize(2 * n);
    sort(xw.begin( ), xw.end( ));

    int sum = 0;
    for (auto &it : xw) sum += it[1];
    cout << sum << endl;

    for (int i = 0; i < n; i++) cout << xw[i][2] << " " << xw[2 * n - i - 1][2] << endl;
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
