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
    vector<char> d(n + m - 1);
    for (char &c : d) cin >> c;

    map<int, int> rc, cc;

    pii st = {0, 0};
    vector<pii> path;
    path.push_back(st);
    for (int i = 0; i < n + m - 1; i++) {
        if (d[i] == 'R') {
            st.second++;
        } else if (d[i] == 'D') {
            st.first++;
        } else if (d[i] == 'L') {
            st.second--;
        } else {
            st.first--;
        }
    }
    path.push_back(st);

    for (auto [r, c] : path) {
        rc[r]++;
        cc[c]++;
    }

    dbg(rc);
    dbg(cc);
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
