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

struct in {
    int l, r, id;
};

void solve( ) {
    int n;
    cin >> n;
    vector<in> lr(n);
    for (int i = 0; i < n; i++) {
        cin >> lr[i].l >> lr[i].r;
        lr[i].id = i;
    }

    sort(lr.begin( ), lr.end( ), [](in a, in b) {
        return a.l < b.l;
    });

    vector<int> res(n);
    for (int i = n / 2; i < n; i++) res[lr[i].id] = 1;

    for (int i : res) cout << i;
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
