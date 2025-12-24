
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
    string s;
    cin >> s;

    char x = min_element(s.begin( ), s.end( ))[0];
    int idx = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == x) {
            idx = i;
            break;
        }
    }

    cout << s[idx] + s.substr(0, idx) + s.substr(idx + 1) << endl;
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
