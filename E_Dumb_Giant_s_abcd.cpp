#include<bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<int> st;

    for (int i = 0; i < n; i++) {
        if (islower(s[i])) st.insert(i);
    }

    vector<int> a;

    for (int it : st) {
        a.push_back(it);
    }

    for (int i = 1; i < n - 1; i++) {
        if ((a[i - 1] + 1 == a[i]) and (a[i - 1] + 2 == a[i + 1 ])) {
            a.erase(a.begin() + i + 1);
        }
    }
}

int32_t main() {
    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}