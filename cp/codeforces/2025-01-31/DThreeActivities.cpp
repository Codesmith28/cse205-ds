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
    vector<pii> a(n, {1, 1}), b(n, {2, 2}), c(n, {3, 3});
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(a.begin( ), a.end( ), greater<pii>( ));
    sort(b.begin( ), b.end( ), greater<pii>( ));
    sort(c.begin( ), c.end( ), greater<pii>( ));

    /*dbg(a, b, c);*/

    int ans = ninf;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                bool c1 = a[i].second != b[j].second;
                bool c2 = b[j].second != c[k].second;
                bool c3 = c[k].second != a[i].second;
                if (c1 && c2 && c3) {
                    int sum = a[i].first + b[j].first + c[k].first;
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;
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
