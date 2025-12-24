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
    int a, b;
    cin >> a >> b;
    int kx, ky, qx, qy;
    cin >> kx >> ky >> qx >> qy;

    vector<int> dx = {-1, 1, -1, 1};
    vector<int> dy = {-1, -1, 1, 1};

    set<pii> king, queen;
    for (int i = 0; i < 4; i++) {
        king.insert({kx + dx[i] * a, ky + dy[i] * b});
        king.insert({kx + dx[i] * b, ky + dy[i] * a});
        queen.insert({qx + dx[i] * a, qy + dy[i] * b});
        queen.insert({qx + dx[i] * b, qy + dy[i] * a});
    }

    int cnt = 0;
    for (auto x : king) if (queen.count(x)) cnt++;
    cout << cnt << endl;
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
