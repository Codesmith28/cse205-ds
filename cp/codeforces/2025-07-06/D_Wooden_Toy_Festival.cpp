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
    sort(a.begin( ), a.end( ));

    auto check = [&](int time) {
        int wi = 0;
        int w = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] - a[wi] > 2 * time) {
                wi = i;
                w++;
            }
        }
        return w <= 3;
    };

    int l = 0, r = 1e9;
    int time = l;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            time = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << time << endl;
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
