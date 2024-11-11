#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n and j < n) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            break;
        }
    }

    if (i == 0) {
        cout << m + n << endl;
    } else {
        int ans = i + 1;
        ans += (n - i) + (m - j);
        cout << ans << endl;
    }
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