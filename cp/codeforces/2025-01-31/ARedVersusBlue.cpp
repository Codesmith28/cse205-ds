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
    int n, r, b;
    cin >> n >> r >> b;

    int quo = r / (b + 1);
    int rem = r % (b + 1);

    string s;
    for (int i = 0; i < b + 1; i++) {
        s += string(quo + (rem > 0 ? 1 : 0), 'R');
        if (rem > 0) rem--;
        if (i < b) s += 'B';
    }

    cout << s << endl;
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
