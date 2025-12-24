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
const int mod = 1e9 + 7;

#include <iostream>
#include <map>
#include <string>
using namespace std;

void solve( ) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<char> conv(26);
    for (char c = 'a'; c <= 'z'; c++) conv[c - 'a'] = c;

    while (m--) {
        char x, y;
        cin >> x >> y;
        for (int i = 0; i < 26; i++) {
            if (conv[i] == x)
                conv[i] = y;
            else if (conv[i] == y)
                conv[i] = x;
        }
    }

    for (char &c : s) c = conv[c - 'a'];
    cout << s << endl;
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
