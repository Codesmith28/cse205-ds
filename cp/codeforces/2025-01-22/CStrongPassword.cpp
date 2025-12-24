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
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    int n = s.size( );
    int mx = -1; // last idx of char in main password

    for (int i = 0; i < m; i++) {
        int last = mx;
        for (char c = l[i]; c <= r[i]; c++) {
            int curr = n;
            // get first idx from here:
            for (int j = mx + 1; j < n; j++) {
                if (s[j] == c) {
                    curr = j;
                    break;
                }
            }
            last = max(last, curr);
        }
        mx = last;
    }

    cout << (mx < n ? "NO" : "YES") << endl;
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
