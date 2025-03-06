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

    if (n < 25) {
        cout << -1 << endl;
        return;
    }

    bool flag = false;
    int x, y;
    for (int i = 5; i <= n; i++) {
        if (n % i == 0) {
            int a = n / i;
            if (a >= 5) {
                flag = true;
                x = i, y = n / i;
                break;
            }
        }
    }

    if (!flag) {
        cout << -1 << endl;
        return;
    }

    vector<vector<char>> ans(x, vector<char>(y, ' '));
    string v = "aeiou";

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ans[i][j] = v[(i + j) % 5];
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << ans[i][j];
        }
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
