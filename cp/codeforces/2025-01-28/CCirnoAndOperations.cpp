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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    auto sum = [&](vector<int> &a) -> int {
        return accumulate(a.begin( ), a.end( ), 0LL);
    };

    int res = sum(a);
    while (a.size( ) > 1) {
        vector<int> b;
        for (int i = 0; i < a.size( ) - 1; i++) b.push_back(a[i + 1] - a[i]);

        vector<int> c;
        reverse(a.begin( ), a.end( ));
        for (int i = 0; i < a.size( ) - 1; i++) c.push_back(a[i + 1] - a[i]);

        int s1 = sum(b);
        int s2 = sum(c);

        s1 > s2 ? a = b : a = c;
        res = max({res, s1, s2});
    }

    cout << res << endl;
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
