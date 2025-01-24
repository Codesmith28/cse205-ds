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
    vector<pii> xy(n);
    for (pii &i : xy) cin >> i.first >> i.second;
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    auto get_dist = [&](int x1, int y1, int x2, int y2) -> int {
        return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    int d1 = get_dist(ax, ay, bx, by);
    for (int i = 0; i < n; i++) {
        int d2 = get_dist(bx, by, xy[i].first, xy[i].second);
        if (d1 >= d2) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
