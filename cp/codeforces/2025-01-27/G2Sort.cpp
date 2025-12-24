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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> pref(n, 0);
    for (int i = 1; i < n; i++) {
        double div = (1.0 * a[i - 1]) / a[i];
        pref[i] = pref[i - 1] + (div < 2.0);
    }

    map<int, int> fq;
    for (int i = 0; i <= k; i++) {
        fq[pref[i]]++;
    }

    int res = 0;
    if (fq.size( ) == k + 1) res++;

    for (int i = k + 1; i < n; i++) {
        fq[pref[i - k - 1]]--;
        if (fq[pref[i - k - 1]] == 0) fq.erase(pref[i - k - 1]);

        fq[pref[i]]++;

        if (fq.size( ) == k + 1) res++;
    }

    cout << res << endl;
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
