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
    vector<pii> movie(n);
    for (auto &it : movie) cin >> it.first >> it.second;
    sort(movie.begin( ), movie.end( ), [](pii a, pii b) {
        return a.second < b.second;
    });

    int cnt = 0;
    int en = -1;
    for (auto it : movie) {
        if (it.first >= en) {
            en = it.second;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}