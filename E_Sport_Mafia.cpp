#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    int counter = 1;

    if (n == k) cout << 0 << endl;

    else {
        for (int i = 0; i <= n; i++) {
            int a = i;
            int b = n - i;

            int x = (a * (a + 1));
            x /= 2;
            if (x - b == k) {
                cout << b << endl;
            }
        }
    }
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}