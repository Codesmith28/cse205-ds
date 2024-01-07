#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    if (n > x) {
        cout << "NO\n";
        return;
    }
    else {
        x -= n;
        n = max(0LL, n - x);
        if (n * 3 <= y) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
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