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
    vector<pii> a(n);

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = {x, i};
    }

    sort(a.begin( ), a.end( ));

    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[a[i].second] = i;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (abs(idx[i] - idx[i - 1]) > 1) cnt++;
    }

    cout << cnt << endl;
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
