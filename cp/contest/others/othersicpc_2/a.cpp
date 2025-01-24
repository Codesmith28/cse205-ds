#include <bits/stdc++.h>
using namespace std;

/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int n, m;
    cin >> n >> m;

    vector<pii> x(n), y(m);
    for (int i = 0; i < n; i++) cin >> x[i].first >> x[i].second; // x-coord, y-speed
    for (int i = 0; i < m; i++) cin >> y[i].first >> y[i].second; // y-coord, x-speed

    map<double, int> ta;

    auto norm = [](double angle) -> double {
        return 90.0 - angle;
    };

    for (int i = 0; i < n; i++) {
        double angle = atan2(x[i].second, x[i].first) * 180.0 / M_PI;
        ta[angle]++;
        ta[norm(angle)]++;
    }

    for (int i = 0; i < m; i++) {
        double angle = atan2(y[i].second, y[i].first) * 180.0 / M_PI;
        ta[angle]++;
        ta[norm(angle)]++;
    }

    /*for (auto it : ta) cout << it.first << "  " << it.second << endl;*/

    int cnt = 0;
    for (auto i : ta) {
        if (ta[norm(i.first)] != 0) {
            ta[i.first]--;
            ta[norm(i.first)]--;
            cnt++;
        }
    }

    cout << cnt / 2 << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
