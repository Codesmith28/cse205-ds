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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (n == k) {
        vector<int> b;
        for (int i = 1; i < n; i += 2) b.push_back(a[i]);
        b.push_back(0);
        for (int i = 0; i < b.size( ); i++) {
            int idx = i + 1;
            if (b[i] != idx) {
                cout << idx << endl;
                return;
            }
        }
    }

    bool flag = true;
    for (int i = 1; i < n - k + 2; i++) {
        if (a[i] != 1) {
            flag = false;
            break;
        }
    }

    cout << (flag ? 2 : 1) << endl;
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
