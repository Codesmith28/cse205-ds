#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;

    string s = "aeiou";

    if (n <= 5) {
        cout << s.substr(0, n) << endl;
        return;
    }

    int fq = n / 5;
    int rem = n % 5;

    string ans = "";
    int c = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < fq; j++) ans += s[c];
        if (rem > 0) ans += s[c];
        rem--;
        c++;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}