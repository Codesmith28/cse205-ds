#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

#define int  long long
#define pii  pair<int, int>
#define endl "\n"

const int inf = 1e18;
const int ninf = -1 * inf;
int mod = 1e9 + 7;

void solve( ) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    auto recur = [&](auto &&self, int i, int sum) -> int {
        if (i == n) return 0;
        int curr = 0;
        for (int r = i; r < n; r++) {
            curr += a[r];
            if (curr > sum) return n;
            if (curr == sum) {
                int len = r - i + 1;
                int next = self(self, r + 1, sum);
                return max(len, next);
            }
        }
        return n;
    };

    int sum = 0, ans = n;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = min(ans, recur(recur, 0, sum));
    }

    cout << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;

    while (test_cases--) {
        solve( );
    }

    return 0;
}
