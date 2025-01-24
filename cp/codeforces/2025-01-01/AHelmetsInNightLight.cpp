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
    int n, p;
    cin >> n >> p;
    vector<pii> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;

    // cheif can share with everyone:
    ab.push_back({n + 1, p});
    sort(ab.begin( ), ab.end( ), [&](pii a, pii b) {
        return a.second < b.second;
    });

    int sum = p;
    int total = 1, idx = 0;

    while (total < n) {
        int rem = n - total;
        if (ab[idx].first <= rem) {
            total += ab[idx].first;
            sum += ab[idx].second * ab[idx].first;
        } else {
            total = n;
            sum += ab[idx].second * rem;
        }
        idx++;
    }

    cout << sum << endl;
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
