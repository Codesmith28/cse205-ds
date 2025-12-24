#include <bits/stdc++.h>
using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int long long
#define pii pair<int, int>
#define endl "\n"

void solve() {
    int e;
    cin >> e;
    int n, m;

    pair<int, int> p = {0, LONG_LONG_MAX};
    while (e--) {
        cin >> n >> m;
        m = n - m;
        vector<int> a(n + 2);

        a[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        a[n + 1] = LONG_LONG_MAX;

        p.first = max(p.first, a[m]);
        p.second = min(p.second, a[m + 1]);
    }

    if (p.first <= p.second)
        cout << p.first << endl;
    else
        cout << "False Hypothesis" << endl;
}

int32_t main() {
    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}