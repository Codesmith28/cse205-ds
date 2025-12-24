#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
#include <ostream>

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;

void solve( ) {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }

    if (k == n || k == 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> meds;
    meds.push_back(1);
    if (k % 2 == 1) {
        meds.push_back(k - 1);
        meds.push_back(k);
        meds.push_back(k + 1);
        meds.push_back(n);
    } else {
        meds.push_back(k);
        meds.push_back(k + 1);
    }

    cout << meds.size( ) << endl;
    for (auto x : meds) cout << x << " ";
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