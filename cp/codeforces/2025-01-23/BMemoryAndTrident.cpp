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
    map<char, int> fq;
    for (char c : s) fq[c]++;

    int d1 = abs(fq['L'] - fq['R']);
    int d2 = abs(fq['U'] - fq['D']);

    if ((d1 + d2) % 2 == 0) {
        cout << (d1 + d2) / 2 << endl;
    } else {
        cout << -1 << endl;
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
