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

vector<int> sum(2e5 + 1, 0);
vector<int> a(2e5 + 1, 0);

void solve() {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] + a[l] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;

    auto calc = [](int x) -> int {
        int cnt = 0;
        while (x) {
            x /= 3;
            cnt++;
        }
        return cnt;
    };

    sum[0] = 0;
    for (int i = 1; i < 2e5 + 1; i++) {
        a[i] = calc(i);
        sum[i] = sum[i - 1] + calc(i);
    }

    while (testCases--) {
        solve();
    }

    return 0;
}