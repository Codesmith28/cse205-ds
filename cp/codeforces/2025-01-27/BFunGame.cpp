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
    string s, t;
    cin >> s >> t;

    vector<int> p1(n);
    p1[0] = (s[0] == '1');
    for (int i = 1; i < n; i++) p1[i] = p1[i - 1] + (s[i] == '1');

    if (s[0] != t[0] && s[0] == '0') {
        cout << "NO" << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] != t[i]) {
            if (s[i] == '0' && p1[i] < 1) { // we need to set this
                cout << "NO" << endl;
                return;
            } else if (s[i] == '1' && p1[i] < 1) { // we need to unset this bit
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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
