#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<pii> times;
    for (int i = 0; i < n; i++) {
        int st, en;
        cin >> st >> en;
        times.push_back({st, 1});
        times.push_back({en, -1});
    }

    sort(begin(times), end(times));
    int curr = 0, ans = 0;
    for (auto it : times) {
        curr += it.second;
        ans = max(ans, curr);
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