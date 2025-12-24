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
    string s;
    cin >> s;

    int n = s.size( );

    if (s[0] == 'B' || s[n - 1] == 'B') {
        int cnt = 0;
        for (char c : s) {
            if (c == 'A') cnt++;
        }
        cout << cnt << endl;
        return;
    }

    vector<int> a, b;
    int cnt = 0;
    bool ca = (s[0] == 'A');

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            if (!ca) {
                b.push_back(cnt);
                cnt = 0;
            }
            cnt++;
            ca = true;
        } else {
            if (ca) {
                a.push_back(cnt);
                cnt = 0;
            }
            cnt++;
            ca = false;
        }
    }

    if (cnt) {
        if (ca) {
            a.push_back(cnt);
        } else {
            b.push_back(cnt);
        }
    }

    int ans = 0;

    bool c1 = false;
    for (int i : b) {
        if (i > 1) c1 = true;
    }

    if (c1) {
        for (int i : a) ans += i;
    } else {
        sort(a.begin( ), a.end( ));
        for (int i = 1; i < a.size( ); i++) ans += a[i];
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
