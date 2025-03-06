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
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int &i : l) cin >> i;
    for (int &i : r) cin >> i;

    map<int, int> fq;
    for (int i = 0; i < n; i++) fq[l[i]] += (l[i] == r[i]);
    map<int, int> pref;
    for (int i = 0; i < 2 * n; i++) {
        pref[i] = pref[i - 1] + (fq[i]);
    }

    for (int i = 0; i < n; i++) {
        int cnt = pref[r[i] + 1] - pref[l[i]];
        if (l[i] == r[i]) cnt--;
        if (r[i] - l[i] + 1 > cnt)
            cout << 1;
        else
            cout << 0;
    }

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
