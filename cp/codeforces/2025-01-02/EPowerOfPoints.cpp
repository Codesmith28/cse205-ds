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
    vector<pii> x(n);
    int s1 = 0, s2 = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
        s2 += x[i].first;
    }

    sort(x.begin( ), x.end( ));
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        s1 += x[i].first;
        s2 -= x[i].first;
        ans[x[i].second] = n + x[i].first * (2 * (i + 1) - n) - s1 + s2;
    }

    for (int &i : ans) cout << i << " ";
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
