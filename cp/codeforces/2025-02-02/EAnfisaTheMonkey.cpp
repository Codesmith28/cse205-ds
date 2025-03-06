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
    int k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;

    int n = s.length( );
    int q = n / k;

    if (n < k * a || n > k * b) {
        cout << "No solution" << endl;
        return;
    }

    int start = 0;
    int rem = n - k * a;

    for (int i = 0; i < k; i++) {
        int extra = min(b - a, rem);
        int len = a + extra;
        cout << s.substr(start, len) << endl;
        start += len;
        rem -= extra;
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
