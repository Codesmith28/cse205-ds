#include <bits/stdc++.h>
#include <string>
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
    string s, t;
    cin >> s >> t;

    vector<int> idx;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            idx.push_back(i);
        }
    }

    if (idx.size() % 2) {
        cout << "impossible" << endl;
        return;
    }

    bool flag = true;
    for (int i = 0; i < idx.size(); i++) {
        if (flag) s[idx[i]] = t[idx[i]];
        flag = !flag;
    }

    cout << s << endl;
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