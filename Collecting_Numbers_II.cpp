#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i] - 1] = i; // store idx
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i - 1]) { // check idx
            ans++;
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