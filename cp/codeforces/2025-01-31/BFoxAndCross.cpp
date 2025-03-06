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
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int hcnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                hcnt++;
            }
        }
    }

    if (hcnt % 5 != 0) {
        cout << "NO" << endl;
        return;
    }

    vector<int> dir = {0, 1, 0, -1, 0};

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (a[i][j] == '#') {
                bool valid = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dir[k], ny = j + dir[k + 1];
                    if (a[nx][ny] != '#') {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    a[i][j] = '.';
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dir[k], ny = j + dir[k + 1];
                        a[nx][ny] = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
