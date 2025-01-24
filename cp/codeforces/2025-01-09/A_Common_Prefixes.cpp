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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    // as the len of string does not exceed 200, we can use a string of 200 length
    string s = string(200, 'a');
    cout << s << endl;

    for (int &i : a) {
        // toggle the ith character of the string to differentiate the strings
        s[i] = (s[i] == 'a' ? 'b' : 'a');
        cout << s << endl;
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