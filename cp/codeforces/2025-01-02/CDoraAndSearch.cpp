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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (n <= 2) {
        cout << -1 << endl;
        return;
    }

    int l = 0, r = n - 1;
    int mn = 1, mx = n;

    while (l <= r) {
        if (a[l] == mn) {
            l++;
            mn++;
        } else if (a[r] == mn) {
            r--;
            mn++;
        } else if (a[l] == mx) {
            l++;
            mx--;
        } else if (a[r] == mx) {
            r--;
            mx--;
        } else {
            break;
        }
    }

    if (l <= r) {
        cout << l + 1 << " " << r + 1 << endl;
    } else {
        cout << -1 << endl;
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
