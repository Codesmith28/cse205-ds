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

    if (s[1] == '=') {
        if (s[0] == s[2]) {
            cout << s << endl;
        } else {
            if (s[0] < s[2]) {
                cout << s[0] << "<" << s[2] << endl;
            } else {
                cout << s[0] << ">" << s[2] << endl;
            }
        }
    } else if (s[1] == '<') {
        if (s[0] < s[2]) {
            cout << s << endl;
        } else {
            if (s[0] == s[2]) {
                cout << s[0] << "=" << s[2] << endl;
            } else {
                cout << s[0] << ">" << s[2] << endl;
            }
        }
    } else {
        if (s[0] > s[2]) {
            cout << s << endl;
        } else {
            if (s[0] == s[2]) {
                cout << s[0] << "=" << s[2] << endl;
            } else {
                cout << s[0] << "<" << s[2] << endl;
            }
        }
    }
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
