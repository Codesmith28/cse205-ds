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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> s(n), r(n);
    for (int &i : s) cin >> i;
    for (int &i : r) cin >> i;

    vector<pair<double, double>> banks;
    for (int i = 0; i < n; i++) banks.push_back(make_pair(r[i], s[i]));
    sort(banks.begin( ), banks.end( ));

    double sum = accumulate(s.begin( ), s.end( ), 0.0);
    double res = 0.0;
    int idx = 0;

    for (int day = m; day >= 1 && idx < n; day--) {
        double amount = t;

        while (idx < n && amount > 1e-9) {
            auto &[rate, rem] = banks[idx];
            double growth = pow(1.0 + (rate / 1e6), day);
            double canTake = amount / growth;

            if (rem > canTake) {
                rem -= canTake;
                res += canTake;
                amount = 0;
            } else {
                double cost = rem * growth;
                res += rem;
                amount -= cost;
                rem = 0;
                idx++;
            }
        }
    }

    res = min(res, sum);
    cout << fixed << setprecision(12) << res << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve( );
    }

    return 0;
}