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
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }

    dbg(p);

    int l = (n + 1) / 2;
    int r = (n + 2) / 2;

    while (l > 0 && (l == r || (p[l] < p[l + 1] && p[r - 1] < p[r]))) {
        l--;
        r++;
    }

    cout << (n - r + 1 + l) / 2 << endl;
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
