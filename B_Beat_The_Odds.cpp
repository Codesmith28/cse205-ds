#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    int o = 0, e = 0;

    while (n--) {
        int x;
        cin >> x;
        x % 2 == 0 ? e++ : o++;
    }
    cout << min(e, o) << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}