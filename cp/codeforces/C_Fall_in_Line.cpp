#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve(int tc) {
    int n;
    cin >> n;
    vector<pii> xy(n);
    for (pii &i : xy) cin >> i.first >> i.second;

    int ans = 1;
    for (int i = 0; i < n; i++) {
        map<pii, int> slope;
        int same = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x = xy[j].first - xy[i].first;
            int y = xy[j].second - xy[i].second;
            if (x == 0 && y == 0) {
                same++;
                continue;
            }
            int g = __gcd(x, y);
            x /= g;
            y /= g;
            slope[{x, y}]++;
            ans = max(ans, slope[{x, y}] + same + 1);
        }
    }

    cout << "Case #" << tc << ": " << n - ans << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        solve(i + 1);
    }
    return 0;
}