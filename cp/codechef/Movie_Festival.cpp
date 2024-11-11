#include <bits/stdc++.h>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for (pii &i : v) cin >> i.first >> i.second;

    sort(v.begin(), v.end(), [](pii a, pii b) { return a.second < b.second; });

    int ans = 0, end = 0;
    for (pii i : v) {
        if (i.first >= end) {
            ans++;
            end = i.second;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}