#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int a, b;
    cin >> a >> b;

    if ((a + b) % 2 == 1) {
        cout << "Alice" << endl;
    }
    else {
        cout << "Bob" << endl;

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