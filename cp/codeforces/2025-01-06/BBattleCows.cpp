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
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> a(n), cp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cp[i] = a[i];
    }

    int ans1 = 0, ans2 = 0;

    swap(a[0], a[k]);
    for (int i = 1; i < n; i++) {
        if (a[0] > a[i])
            ans1++;
        else
            break;
    }

    for (int i = 0; i < k; i++) {
        if (cp[i] > cp[k]) {
            swap(cp[i], cp[k]);
            k = i;
            break;
        }
    }
    if (k != 0) ans2++;
    for (int i = k + 1; i < n; i++) {
        if (cp[k] > cp[i])
            ans2++;
        else
            break;
    }

    cout << max(ans1, ans2) << endl;
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
