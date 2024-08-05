#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '(' and s[i] == '_') s[i] = ')';
    }

    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] == ')' and s[i] == '_') s[i] = '(';
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '_') s[i] = '(';
    }

    // cout << s << endl;

    // gaps between ( and )
    int ans = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int x = st.top();
            st.pop();
            ans += i - x;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}