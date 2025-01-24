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

    auto maker = [&](auto &&self, int n, int k) -> vector<int> {
        if (n == 0) return { };
        if (k < n) {
            vector<int> a(n, -1);
            if (k > 0) a[k - 1] = 200;
            a[k] = -400;
            return a;
        } else {
            vector<int> a = self(self, n - 1, k - n);
            a.push_back(1000);
            return a;
        }
    };

    vector<int> res = maker(maker, n, k);
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) solve( );
    return 0;
}
