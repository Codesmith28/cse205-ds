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
    int n, c;
    cin >> n >> c;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];
    sort(stalls.begin( ), stalls.end( ));

    auto chk = [&](int mid) -> bool {
        int last_pos = stalls[0];
        int cows_placed = 1;

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last_pos >= mid) {
                cows_placed++;
                last_pos = stalls[i];
                if (cows_placed == c) return true;
            }
        }

        return false;
    };

    int l = 0, r = 1e9;
    int res = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (chk(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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
