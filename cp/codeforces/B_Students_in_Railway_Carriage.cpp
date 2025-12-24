#include <algorithm>
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
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    vector<int> segments;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            cnt++;
        } else {
            segments.push_back(cnt);
            cnt = 0;
        }
    }
    segments.push_back(cnt);
    sort(begin(segments), end(segments));

    int ans = 0;

    for (int it : segments) {
        // a is smaller
        if (a > b) {
            swap(a, b);
        }

        if (it % 2 == 0) {
            int x = it / 2;
            ans += min(a, x);
            ans += min(b, x);
            a -= min(a, x);
            b -= min(b, x);
        } else {
            int x = it / 2;
            int y = (it + 1) / 2;
            ans += min(a, x);
            ans += min(b, y);
            a -= min(a, x);
            b -= min(b, y);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}