#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    unordered_map<int, int> dp;
    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (dp[a[i]] > ans) {
            ans = dp[a[i]];
            last = a[i];
        }
    }

    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == last) {
            res.push_back(i + 1);
            last--;
        }
    }

    reverse(begin(res), end(res));
    cout << res.size() << endl;
    for (int i : res) cout << i << " ";
    cout << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}