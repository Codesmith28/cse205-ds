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
    string s;
    cin >> s;

    int n = s.size( );
    vector<int> pref(n);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '(') {
            pref[i] = pref[i - 1] + 1;
        } else {
            pref[i] = pref[i - 1] - 1;
        }
    }

    vector<tuple<int, int, char>> res(n);
    for (int i = 0; i < n; i++) res[i] = {pref[i], i, s[i]};

    sort(res.begin( ), res.end( ), [&](tuple<int, int, char> a, tuple<int, int, char> b) {
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    string ans;
    for (auto &x : res) ans += get<2>(x);

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
