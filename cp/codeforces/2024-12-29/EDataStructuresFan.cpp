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

    string s;
    cin >> s;

    int xor_1, xor_0;
    xor_1 = xor_0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            xor_1 ^= a[i];
        } else {
            xor_0 ^= a[i];
        }
    }

    vector<int> xor_prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) xor_prefix[i] = xor_prefix[i - 1] ^ a[i - 1];

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            int xor_sum = xor_prefix[y] ^ xor_prefix[x - 1];

            xor_1 ^= xor_sum;
            xor_0 ^= xor_sum;
        } else {
            int g;
            cin >> g;

            if (g == 0) {
                cout << xor_0 << endl;
            } else {
                cout << xor_1 << endl;
            }
        }
    }
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
