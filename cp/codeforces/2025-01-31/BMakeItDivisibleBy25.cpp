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
    int n = s.length( );
    vector<string> l2 = {"25", "50", "75", "00"};
    const int inf = 1e9;

    auto match = [&](const string &s, const string &t) -> int {
        int p = n - 1, res = 0;
        while (p >= 0 && s[p] != t[1]) {
            p--;
            res++;
        }
        if (p < 0) return inf;
        p--;
        while (p >= 0 && s[p] != t[0]) {
            p--;
            res++;
        }
        if (p < 0) return inf;
        return res;
    };

    int ans = inf;
    for (int i = 0; i < 4; i++) ans = min(ans, match(s, l2[i]));
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
