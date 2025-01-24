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
    int n, k;
    cin >> n >> k;

    /*total ways for max sum -> 2*2*2...(n-1)*1 => 2^(n-1)*/
    /*int mx_p = (1 << (n - 1));*/

    auto mx_p = [&](int x) -> long long {
        if (x - 1 >= 60) return LLONG_MAX; // Prevent overflow
        return (1LL << (x - 1));
    };

    if (mx_p(n) < k) {
        cout << -1 << endl;
        return;
    }

    vector<int> res(n);
    int l = 0, r = n - 1;

    for (int i = 1; i <= n; i++) {
        if (mx_p(n - i) < k) {
            k -= mx_p(n - i);
            res[r--] = i;
        } else {
            res[l++] = i;
        }
    }

    for (int i : res) cout << i << " ";
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
