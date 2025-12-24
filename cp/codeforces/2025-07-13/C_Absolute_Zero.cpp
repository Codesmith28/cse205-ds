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
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0, zeros = 0;
    for (int &x : a) {
        cin >> x;
        (x & 1) ? odd++ : even++;
        if (x == 0) zeros++;
    }

    // base case
    if (odd != 0 && even != 0) {
        cout << -1 << endl;
        return;
    }
    if (zeros == n) {
        cout << 0 << endl;
        cout << endl;
        return;
    }
    if (n == 1) {
        cout << 1 << endl;
        cout << a[0] << endl;
        return;
    }

    vector<int> ops;
    for (int i = 29; i >= 0; i--) ops.push_back(1LL << i);
    if (even != 0) ops.push_back(1);

    cout << ops.size( ) << endl;
    for (int i : ops) cout << i << " ";
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