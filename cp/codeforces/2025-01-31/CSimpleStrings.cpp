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
    int n = s.length( );

    if (n == 1) {
        cout << s << endl;
        return;
    }

    string consec = "", res = "";
    s += '#';

    for (int i = 0; i < n; i++) {
        consec += s[i];

        if (s[i] != s[i + 1]) {
            int m = consec.length( );
            if (m > 1) {
                char rep = ' ';
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c != consec[0] && c != s[i + 1]) {
                        rep = c;
                        break;
                    }
                }

                for (int j = 1; j < m; j += 2) consec[j] = rep;
            }
            res += consec;
            consec = "";
        }
    }

    cout << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
