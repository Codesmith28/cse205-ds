#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int k, n, w;
    cin >> k >> n >> w;

    int sum = 0;
    for (int i = 1; i <= w; i++) {
        sum += i * k;
    }

    int diff = sum - n;

    if (diff <= 0)
        cout << 0 << endl;
    else
        cout << diff << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}