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
    int x, y, k;
    cin >> x >> y >> k;

    int a = x * k, b = y * k;

    vector<int> l(k), m(k);
    for (int i = 0; i < k; i++) {
        l[i] = a / k;
        m[i] = b / k;
    }

    for (int i = 0; i < k; i++) {
        l[i] += i + 1;
        l[k - i - 1] -= i + 1;
        m[i] += i + 1;
        m[k - i - 1] -= i + 1;
    }

    for (int i = 0; i < k; i++) {
        cout << l[i] << " " << m[i] << endl;
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