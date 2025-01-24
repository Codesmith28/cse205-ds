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
    vector<vector<char>> a(n, vector<char>(n));
    vector<pii> pos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
                pos.push_back({i, j});
            }
        }
    }

    pii x = pos[0], y = pos[1];

    if (pos[0].first == pos[1].first) { // if same col:
        x.first = (x.first + 1) % n;
        y.first = (y.first + 1) % n;
    } else if (pos[0].second == pos[1].second) { // if same row:
        x.second = (x.second + 1) % n;
        y.second = (y.second + 1) % n;
    } else {
        swap(x.first, y.first);
    }

    a[x.first][x.second] = '*';
    a[y.first][y.second] = '*';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
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
