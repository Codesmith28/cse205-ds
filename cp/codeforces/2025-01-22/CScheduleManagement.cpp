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
    vector<int> a(m);
    for (int &i : a) cin >> i;
    for (int &i : a) i--;
    map<int, int> fq;
    for (int &i : a) fq[i]++;

    int l = 1, r = 2 * m;
    int res = 0;

    auto chk = [&](int time) -> bool {
        int done = 0, not_done = 0;
        for (int i = 0; i < n; i++) {
            if (time >= fq[i]) {
                done += (time - fq[i]) / 2;
            } else {
                not_done += fq[i] - time;
            }
        }
        return done >= not_done;
    };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (chk(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
