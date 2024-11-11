#include <bits/stdc++.h>
#include <iterator>
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
    for (int &i : a) cin >> i;

    sort(rbegin(a) + 1, rend(a));

    int cnt = 1, tc = 0;
    while (true) {
        if (cnt >= n) break;
        bool notPOssible = false;
        tc = 0;

        for (int i = 0; i < cnt; i++) {
            for (int j = cnt; j < n; j++) {
                tc += a[i] * a[j];
                if (tc > c) {
                    notPOssible = true;
                    break;
                }
            }
        }
        if (!notPOssible) {
            cout << cnt << endl;
            return;
        }
        cnt++;
    }

    cout << n << endl;
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