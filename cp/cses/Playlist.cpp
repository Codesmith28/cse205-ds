#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    for (int &i : k) cin >> i;

    int mx = 0, low = 0;
    map<int, int> idx;

    for (int high = 0; high < n; high++) {
        if (idx.find(k[high]) == idx.end()) {
            idx[k[high]] = high;
        } else {
            if (idx[k[high]] >= low) low = idx[k[high]] + 1;
            idx[k[high]] = high;
        }
        mx = max(mx, high - low + 1);
    }

    cout << mx << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}