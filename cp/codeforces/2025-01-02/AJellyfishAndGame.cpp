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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < a[x]) x = i;
    for (int i = 0; i < m; i++)
        if (b[i] > b[y]) y = i;

    if (a[x] < b[y]) swap(a[x], b[y]);

    if (k % 2 == 0) {
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > a[x]) x = i;
        for (int i = 0; i < m; i++)
            if (b[i] < b[y]) y = i;
        swap(a[x], b[y]);
    }

    int sum = accumulate(a.begin( ), a.end( ), 0LL);
    cout << sum << endl;
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
