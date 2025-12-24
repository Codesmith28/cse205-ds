#include <algorithm>
#include <bits/stdc++.h>
#include <string>
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

    auto go = [&](auto &&go, int curr) -> int {
        if (curr == 0) return 0;
        string num = to_string(n);
        char mx = *max_element(num.begin( ), num.end( ));
        int mxdig = mx - '0';
        int cnt = INT_MAX;
    };

    cout << go(go, n) << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}