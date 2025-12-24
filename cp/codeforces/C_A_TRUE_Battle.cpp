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

void solve( ) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool c1 = s[0] == '1' or s[n - 1] == '1';
    bool c2 = false;
    int ones = 0;

    for (char c : s) {
        if (c == '0') {
            ones = 0;
        } else {
            ones++;
            if (ones > 1) {
                c2 = true;
                break;
            }
        }
    }

    cout << (c1 or c2 ? "YES" : "NO") << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}
