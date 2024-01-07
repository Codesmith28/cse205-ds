#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    string s;

    cin >> n >> s;

    int ans = 0;

    for (char c : s) {
        if (c == '+') ans++;
        else ans--;
    }

    cout << abs(ans) << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}