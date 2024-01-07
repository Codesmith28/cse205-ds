#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    int zeros = 0;

    vector<int> a(n);
    for (int& i : a) cin >> i;

    vector<int> b(n);

    // max possible ans:
    int ans = n;
    b[0] = a[0];

    // smallest value upto i:
    for (int i = 1; i < n; i++) {
        b[i] = min(b[i - 1], a[i]);
    }

    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            count++;
            ans = min(ans, n - count + a[i]);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}