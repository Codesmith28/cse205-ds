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
    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<int>> t(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t[i][j];
        }
    }

    for (auto &it : t) sort(it.begin( ), it.end( ));
    int ans = 1;
    pii ref;

    for (int idx = 0; idx < n; idx++) {
        int pts = 0, pen = 0;
        int sum = 0;

        for (int i : t[idx]) {
            if (sum + i <= h) {
                sum += i;
                pen += sum;
                pts++;
            }
        }

        if (idx == 0) {
            ref = {-pts, pen};
        } else {
            pii curr = {-pts, pen};
            if (curr < ref) {
                ans++;
            }
        }
    }

    cout << ans << endl;
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
