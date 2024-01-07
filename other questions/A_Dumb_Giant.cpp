#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;

    while (k--) {


        if (n % 10 == 0) {
            n /= 10;
        }
        else {
            n--;
        }
    }

    cout << n << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}