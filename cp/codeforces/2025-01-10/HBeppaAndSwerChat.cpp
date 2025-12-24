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
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    auto chk_sub = [&](vector<int> &a, vector<int> &b) -> bool {
        int i = 0, j = 0;
        while (i < a.size( ) && j < b.size( )) {
            if (a[i] == b[j]) {
                j++;
            }
            i++;
        }
        return j == b.size( );
    };

    int l = 0, r = n, len = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> b_suff(b.end( ) - mid, b.end( ));
        if (chk_sub(a, b_suff)) {
            len = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << n - len << endl;
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
