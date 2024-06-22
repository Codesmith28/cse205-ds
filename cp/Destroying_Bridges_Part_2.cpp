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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        b.push_back({a[i], i});
    }

    sort(begin(b), end(b));
    // dbg(b);

    // home island isolated:
    int tc = 0;
    for (int i = 1; i < n; i++) {
        tc += a[0] * a[i];
    }
    if (tc <= c) {
        cout << 1 << endl;
        return;
    }

    // trying to isolate each island:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int itc = 0;
        if (b[i].second == 0) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            itc += b[i].first * b[j].first;
        }
        if (itc <= c) {
            cnt++;
            c -= itc;
            b[i] = {0, 0};
        }
        if (itc > c) {
            break;
        }
    }

    cout << n - cnt << endl;
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