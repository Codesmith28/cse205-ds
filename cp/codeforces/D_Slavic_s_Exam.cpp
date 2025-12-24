#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    string s, t;
    cin >> s >> t;

    int idx = 0;
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (idx < m)
                s[i] = t[idx++];
            else
                s[i] = 'a';
        } else if (s[i] == t[idx]) {
            idx++;
        }
    }

    if (idx >= m)
        cout << "YES\n" << s << endl;
    else
        cout << "NO\n";
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}