#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = k; i < n; i++) {
        cout << n - i << " ";
    }
    for (int i = k - 1; i >= 0; i--) {
        cout << n - i << " ";
    }
    cout << endl;

}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}