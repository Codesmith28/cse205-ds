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

    char h0 = s[0], h1 = s[1], m0 = s[3], m1 = s[4];
    if (h0 == m1 && h1 == m0) {
        cout << 0 << endl;
        return;
    }

    auto chk = [&](int h, int m) -> bool {
        return h / 10 == m % 10 && h % 10 == m / 10;
    };

    int ch = (h0 - '0') * 10 + (h1 - '0');
    int cm = (m0 - '0') * 10 + (m1 - '0');

    int time = 0;

    while (true) {
        cm++;
        if (cm == 60) {
            cm = 0;
            ch++;
            if (ch == 24) ch = 0;
        }
        time++;

        if (chk(ch, cm)) {
            cout << time << endl;
            return;
        }
    }
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
