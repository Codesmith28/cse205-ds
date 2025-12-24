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

void solve( ) {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size( );

    while (q--) {
        string x;
        cin >> x;
        int m = x.size( );
        x += x;
        x.pop_back( );
    }
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}