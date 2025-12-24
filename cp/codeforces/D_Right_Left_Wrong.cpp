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
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    string s;
    cin >> s;

    queue<int> ls;
    stack<int> rs;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            ls.push(i + 1);
        } else {
            rs.push(i + 1);
        }
    }

    int l = ls.front();
    int r = rs.top();

    int sum = 0;
    while (!ls.empty() && !rs.empty()) {
        int l = ls.front();
        int r = rs.top();

        if (l < r) {
            sum += (a[r] - a[l - 1]);
            ls.pop();
            rs.pop();
        } else {
            break;
        }
    }

    cout << sum << endl;
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