#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int& i : b) cin >> i;

    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (b[i] == i + 1) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
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