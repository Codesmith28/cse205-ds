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
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> x(n, vector<int>(m, 0));
    vector<vector<int>> y(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x[i][j] = min(a[i][j], b[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            y[i][j] = max(a[i][j], b[i][j]);
        }
    }

    bool f1 = true, f2 = true;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (x[i][j] <= x[i][j - 1]) {
                f1 = false;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (x[i][j] <= x[i - 1][j]) {
                f1 = false;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (y[i][j] <= y[i][j - 1]) {
                f2 = false;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (y[i][j] <= y[i - 1][j]) {
                f2 = false;
                break;
            }
        }
    }

    cout << (f1 && f2 ? "Possible" : "Impossible") << endl;
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
