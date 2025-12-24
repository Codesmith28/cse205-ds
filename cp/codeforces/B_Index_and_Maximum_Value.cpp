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
    int n, m;
    cin >> n >> m;

    int x;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> x;
        st.insert(x);
    }

    int mx = *max_element(begin(st), end(st));

    while (m--) {
        char c;
        int l, r;
        cin >> c >> l >> r;

        if (mx >= l and mx <= r) {
            if (c == '-') {
                mx--;
            } else {
                mx++;
            }
            cout << mx << " ";
        } else {
            cout << mx << " ";
        }
    }
    cout << endl;
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