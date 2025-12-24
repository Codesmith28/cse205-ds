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
    map<int, int> fq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fq[x]++;
    }
    vector<int> fqv;
    for (auto [k, v] : fq) fqv.push_back(v);
    sort(fqv.begin( ), fqv.end( ));

    // dbg(fqv);

    int mx = 0;
    for (int i = 0; i < fqv.size( ); i++) {
        mx = max(mx, fqv[i] * ((int)fqv.size( ) - i));
    }

    cout << mx << endl;
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