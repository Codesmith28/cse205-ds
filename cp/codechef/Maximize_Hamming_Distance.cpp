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
    vector<string> s(m);
    for (auto &i : s) cin >> i;

    int res = 0;

    for (int i = 0; i < n; i++) {
        map<int, int> fq;

        for (int j = 0; j < m; j++) fq[(s[j][i] - '0')]++;
        int q = m - (fq[0] + fq[1]);
        int diff = min(q, abs(fq[0] - fq[1]));

        if (fq[0] <= fq[1]) {
            fq[0] += diff;
        } else {
            fq[1] += diff;
        }

        q -= diff;

        if (q % 2 == 0) {
            fq[0] += q / 2;
            fq[1] += q / 2;
        } else {
            fq[0] += q / 2 + 1;
            fq[1] += q / 2;
        }

        res += fq[0] * fq[1];
    }

    cout << res << endl;
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