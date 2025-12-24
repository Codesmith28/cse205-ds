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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> s(n), p(n);
    for (int &i : s) cin >> i;
    for (int &i : p) cin >> i;

    vector<pii> ps;
    for (int i = 0; i < n; i++) ps.emplace_back(p[i], s[i]);
    sort(ps.begin( ), ps.end( ));

    auto repay = [&](double amo) -> bool {
        double sum = amo;
        vector<double> loans(n);

        for (int i = 0; i < n && sum > 0; i++) {
            loans[i] = min((double)ps[i].second, sum);
            sum -= loans[i];
        }

        if (sum > 1e-9) return false;

        
    };

    double low = 0, high = accumulate(s.begin( ), s.end( ), 0LL);
    double ans = 0;
    while (high - low > 1e-6) {
        double mid = (low + high) / 2;
        if (repay(mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}