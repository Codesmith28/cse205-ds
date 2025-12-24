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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    auto xor_sum = [&](vector<int> &a) -> int {
        int sum = 0;
        for (int i : a) sum ^= i;
        return sum;
    };

    int or_sum = 0;
    for (int i : b) or_sum |= i;

    int mn = 0, mx = 0;
    if (n % 2 == 0) {
        mx = xor_sum(a);
    } else {
        mn = xor_sum(a);
    }

    for (int &i : a) i |= or_sum;
    if (n % 2 == 0) {
        mn = xor_sum(a);
    } else {
        mx = xor_sum(a);
    }

    cout << mn << " " << mx << endl;
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
