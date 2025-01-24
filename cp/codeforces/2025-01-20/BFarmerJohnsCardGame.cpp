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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mp[a[i][j]] = i + 1;
        }
        sort(a[i].begin( ), a[i].end( ));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] - a[i][j - 1] != n) {
                cout << -1 << endl;
                return;
            }
        }
    }

    map<int, int> fq;
    for (int i = 0; i < (m * n); i++) {
        if (fq[mp[i]] == 0) {
            cout << mp[i] << " ";
            fq[mp[i]]++;
        } else {
            break;
        }
    }
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
