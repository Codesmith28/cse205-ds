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
    string s;
    cin >> s; // len = n
    vector<int> idx(m);
    for (int &i : idx) cin >> i;
    string c;
    cin >> c; // len = m

    set<int> idxs;
    for (int i = 0; i < m; i++) idxs.insert(idx[i]);
    int x = idxs.size();
    vector<int> iv(begin(idxs), end(idxs));

    sort(begin(c), end(c));
    c = c.substr(0, x);

    for (int i = 0; i < x; i++) {
        s[iv[i] - 1] = c[i];
    }

    cout << s << endl;
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