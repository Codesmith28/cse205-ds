#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

bool isLuck(int n) {
    string x = to_string(n);
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != '4' && x[i] != '7') {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && isLuck(i)) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}