#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;

    if ((n - m) % 2 == 0 and (n - m) >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}