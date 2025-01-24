#include <bits/stdc++.h>
#include <numeric>
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
    vector<string> s(n);
    for (auto &it : s) cin >> it;

    vector<int> res(n);
    iota(res.begin( ), res.end( ), 0);

    sort(res.begin( ), res.end( ), [&](int x, int y) {
        if (s[x][y] == '1') return x < y;
        else return x > y;
    });

    for (int i : res) cout << i + 1 << " ";
    cout << endl;
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