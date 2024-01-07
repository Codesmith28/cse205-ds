#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    // is x a perfect square:
    int sq = sqrt(sum);
    if (sq * sq == sum) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
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