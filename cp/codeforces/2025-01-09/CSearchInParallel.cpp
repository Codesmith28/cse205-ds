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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pii> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i].first;
        r[i].second = i + 1;
    }

    sort(r.begin( ), r.end( ), greater<pii>( ));
    vector<int> a, b;

    for (int i = 0; i < n; i++) {
        int c1 = s1 * (a.size( ) + 1);
        int c2 = s2 * (b.size( ) + 1);
        if (c1 <= c2) {
            a.push_back(r[i].second);
        } else {
            b.push_back(r[i].second);
        }
    }

    cout << a.size( ) << " ";
    for (int i : a) cout << i << " ";
    cout << endl;

    cout << b.size( ) << " ";
    for (int i : b) cout << i << " ";
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
