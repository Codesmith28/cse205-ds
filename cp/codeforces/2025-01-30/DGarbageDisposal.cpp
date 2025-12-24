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
    int k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    int carry = 0, ans = 0;

    for (int i = 0; i < n; ++i) {
        int curr = a[i] + carry;

        if (curr >= k) {
            ans += curr / k;
            carry = curr % k;
        } else {
            if (curr > 0) {
                if (carry > 0) {
                    ans++;
                    carry = 0;
                } else {
                    carry = a[i];
                }
            }
        }
    }

    if (carry > 0) ans++;
    cout << ans << endl;
}

int32_t main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    /*cin >> test_cases;*/

    while (test_cases--) {
        solve( );
    }

    return 0;
}
