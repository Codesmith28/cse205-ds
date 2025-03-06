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

    auto cnt = [&](int x) -> int {
        int cnt = 0;
        for (int d = 5; d <= x; d *= 5) cnt += x / d;
        return cnt;
    };

    int m = n;

    int l = 0, r = 1e18;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cnt(mid) < m)
            l = mid + 1;
        else
            r = mid;
    }

    int st = l;
    if (cnt(st) != m) {
        cout << 0 << "\n";
        return;
    }

    l = st, r = 1e18;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cnt(mid) <= m)
            l = mid + 1;
        else
            r = mid;
    }
    int en = l - 1;

    cout << (en - st + 1) << endl;
    for (int i = st; i <= en; i++) cout << i << " ";
    cout << endl;
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
