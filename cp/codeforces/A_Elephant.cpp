#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    // elephant is at 0, frnd is at x
    // steps of size: {1,2,3,4,5}
    // min number of steps?

    int x;
   cin >> x;

    int ans = 0;
    ans += x/5;
    if(x%5) ans++;

    cout << ans << endl;
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;
    while(testCases--) {
        solve();
    }
    return 0;
}