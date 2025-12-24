#include <bits/stdc++.h>
using namespace std;

#define int  long long
#define endl "\n"

void solve( ) {
    int n, m, t;
    cin >> n >> m >> t;

    vector<double> s(n), p(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        p[i] = pi * 1e-6;
    }

    auto can_pay = [&](double loan) -> bool {
        vector<double> take(n);
        double remaining = loan;

        for (int i = 0; i < n; ++i) {
            take[i] = min(s[i], remaining);
            remaining -= take[i];
        }

        double total_debt = 0;
        for (int i = 0; i < n; ++i) {
            double growth = pow(1 + p[i], m);
            total_debt += take[i] * growth;
        }

        return total_debt <= m * t;
    };

    double lo = t, hi = accumulate(s.begin( ), s.end( ), 0.0);
    double ans = t;

    while (hi - lo > 1e-12) {
        double mid = lo + (hi - lo) / 2;
        if (can_pay(mid)) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}

int32_t main( ) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve( );
    return 0;
}
