#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> v(n);
    unordered_set<char> st;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
        ans += st.size();
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