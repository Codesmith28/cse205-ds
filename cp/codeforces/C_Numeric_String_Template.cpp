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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;

        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }

        map<char, int> ci;
        map<int, char> ic;

        bool flag = true;
        for (int i = 0; i < n; i++) {
            if ((ci.find(s[i]) == ci.end()) and (ic.find(a[i]) == ic.end())) {
                ci[s[i]] = a[i];
                ic[a[i]] = s[i];
            } else {
                if (ci[s[i]] != a[i] or ic[a[i]] != s[i]) {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
            }
        }

        if (flag) cout << "YES" << endl;
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