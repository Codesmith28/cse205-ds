#include <bits/stdc++.h>
#include <vector>
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
    vector<int> c(m);
    vector<vector<int>> ab(n); // a[i] to make, b[i] on break, xp++ on each process
    for (auto &i : ab) cin >> i[0];
    for (auto &i : ab) cin >> i[1];
    for (int &j : c) cin >> j; // availablity of any ingridient

    sort(begin(ab), end(ab), [](vector<int> &a, vector<int> &b) { return a[1] - a[0] > b[1] - b[0]; });
    sort(rbegin(c), rend(c));

    int xp = 0;

    // maximize xp
    for (int i = 0; i < n; i++) {
        if (c[ab[i][0] - 1] > 0) {
            xp++;
            c[ab[i][0] - 1]--;
        } else if (c[ab[i][1] - 1] > 0) {
            xp++;
            c[ab[i][1] - 1]--;
        }
    }

    cout << xp << endl;
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