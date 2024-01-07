#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (b >= a) {
        cout << 0 << endl;
        return;
    }

    // total data
    int x = a * c;
    float y = x * 1.0 / b;
    cout << ceil(y - c) << endl;

}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}