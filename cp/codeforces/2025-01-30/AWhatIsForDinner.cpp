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
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> dur;

    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        if (dur.find(r) == dur.end( )) {
            dur[r] = c;
        } else {
            dur[r] = min(dur[r], c);
        }
    }

    int ans = 0;
    vector<pii> cr;
    for (auto &it : dur) cr.push_back({it.second, it.first});
    sort(cr.begin( ), cr.end( ), greater<pii>( ));

    for (int i = 0; i < cr.size( ); i++) {
        int take = min(cr[i].first, k);
        ans += take;
        k -= take;
        if (k <= 0) break;
    }

    cout << ans << endl;
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
