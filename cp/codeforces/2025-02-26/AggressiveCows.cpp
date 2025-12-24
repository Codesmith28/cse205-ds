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
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for (int &i : x) cin >> i;
    sort(x.begin( ), x.end( ));

    auto check = [&](int mid) {
        int cows = 1, last = x[0];
        for (int i = 1; i < n; i++) {
            if (x[i] - last >= mid) {
                cows++;
                last = x[i];
            }
        }
        return cows >= c;
    };

    int low = 1, high = x[n - 1] - x[0], ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
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
