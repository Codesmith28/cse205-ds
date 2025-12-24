#include <bits/stdc++.h>
#include <cmath>
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
    int n = s.size( ) - 1;
    vector<int> res;
    for (char c : s) {
        if (c != '0') {
            res.push_back((c - '0') * pow(10, n));
        }
        n--;
    }
    cout << res.size( ) << endl;
    for (int &i : res) cout << i << " ";
    cout << endl;
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